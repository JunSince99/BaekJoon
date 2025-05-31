using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using RTC6Import;
using System.Threading;
using System.Drawing;
using System.Windows.Forms;
using System.IO;


namespace YOUIL_2B
{
    /// <summary>
    /// RTC6 보드 제어 클래스
    /// </summary>
    static class Const
    {

        //공용 출력 주소
        public const UInt32 Output1 = 0x0000_0001;          // 37핀 6번
        public const UInt32 Output2 = 0x0000_0002;          //  37핀 7번
        public const UInt32 Output_EM = 0b_0000_0000_0000_0100;

        public const UInt32 Error_Reset = 0x0000_0100;
        public const UInt32 Laser_Power_Enable = 0x0000_0200;
        public const UInt32 Laser_Emission_Enable = 0x000_0400;
        public const UInt32 Laser_Guide = 0x0000_0800;
        public const UInt32 Laser_Aux_Off = 0x0000_1000;
        public const UInt32 Laser_PPI = 0x0000_2000;


        //제어 출력 RTC0 에만 있음

        public const UInt32 System_Ready = 0x0000_4000;
        public const UInt32 B_Busy = 0x0000_8000;

        //공용 입력 주소

        public const UInt32 Laser_Emergency_Sw = 0x0000_0100;
        public const UInt32 Laser_Fiber_Error = 0x0000_0200;
        public const UInt32 Laser_Power_Check = 0x0000_0400;
        public const UInt32 Laser_Err_Status0 = 0x0000_0800;
        public const UInt32 Laser_Err_Status1 = 0x0000_1000;
        public const UInt32 Laser_Err_Status2 = 0x0000_2000;
        public const UInt32 Laser_Err_Status3 = 0x0000_4000;


        //제어 입력 주소

        public const UInt32 System_Interlock = 0x0000_8000;


        //레이저 파라메타 용 분별자

        public const byte LINE = 1;
        public const byte ARC = 2;
        public const byte LS0_Coated = 0;
        public const byte LS0_Metal = 1;
        public const byte LS0_User1 = 2;
        public const byte LS0_User2 = 3;
        public const byte LS0_User3 = 4;
        public const byte LS1_Coated = 5;
        public const byte LS1_Metal = 6;
        public const byte LS1_User1 = 7;
        public const byte LS1_User2 = 8;
        public const byte LS1_User3 = 9;

    }

    public class RTC
    {

        public string Correction_Filename { get; set; }
        public UInt32 Board_Number { get; set; }
        
        public string LS_IP_Address 
        {
            get
            {
                return Eth.IP_Address;
            }
            set
            {
                Eth.IP_Address = value;
            }
                
        }
        public double scalex { get; set; }
        public double kFactor { get; set; }


        //public float Laser_Power { get; set; }
        //public float Pulse_Duration { get; set; }
        public string Serial_Number { get; set; }
        public int LS_On_Delay { get; set; }
        public UInt32 LS_Off_Delay { get; set; }
        public UInt32 Jump_Delay { get; set; }
        public UInt32 Cut_Delay { get; set; }
        public UInt32 Pol_Delay { get; set; }
        public double Cut_Speed { get; set; }
        public double Jump_Speed { get; set; }
        public double Rep_Rate { get; set; }
        PointF SP = new PointF();   //SP as a start point perpose

        public IPG_Eth Eth { get; set; } = new IPG_Eth();
        public float MOF_Offset_X { get; set; } = 0;
        public float MOF_Offset_Y { get; set; } = 0;
   



        public RTC()
        {
            Correction_Filename= "";
            Board_Number = 1;
            LS_IP_Address = "";
            kFactor = 0;
            scalex = (double)(kFactor / 41.58004d);//(250425 박준현) : 42.57796d-> 변경 41.58004 
            LS_On_Delay = 0;
            LS_Off_Delay = 0;
            Jump_Delay = 0;
            Cut_Delay = 0;
            Pol_Delay = 0;
            Jump_Speed = 5;
        }
        ~RTC()
        {

        }


        /// <summary>
        /// //////////////////////////////250324 이강수
        /// </summary>
        /*
        public bool Eth_Connect()
        {  
            if (_sc != null)
            {
                _sc.Close();
                _sc = null;
            }

            _sc = new Socket(SocketType.Stream, ProtocolType.Tcp);
            IPAddress address = IPAddress.Parse(LS_IP_Address);
            try
            {
                _sc.Connect(address, 5100);
                Is_Connected = true; // Set to true when connection is successful
                return true;
            }
            catch
            {
                //Thread.Sleep(1000);
                MessageBox.Show("Eth not connect");
                Is_Connected = false;
                return false;
            }
            //Is_Connected = true;
            //return true;
        }
        */
        /*
        public void Eth_Close()
        {

            _sc.Close();
            
            return;
        }
        */

        #region private Eth functions
        ///////////////////////
        ///250324 이강수

        /*
        private string make_Command(UInt16 command, string data)
        {

            string str, m_str = string.Empty;
            byte[] ui16_data = new byte[2];
            byte[] ui_data = new byte[4];

            ui16_data = BitConverter.GetBytes(command);
            str = convert_str(ui16_data, 2);
            m_str += str;
            ui16_data = BitConverter.GetBytes((UInt16)0);
            str = convert_str(ui16_data, 2);
            m_str += str;
            ui_data = BitConverter.GetBytes(data.Length);
            str = convert_str(ui_data, 4);
            m_str += str;
            m_str += data;
            ui16_data = BitConverter.GetBytes(Get_Crc16(m_str));
            str = convert_str(ui16_data, 2);
            m_str += str;

            return m_str;
        }
        */
        /*
        private string convert_str(byte[] data, int length)
        {
            string str = string.Empty;
            for (int i = 0; i < length; i++)
            {
                str += (char)data[i];
            }
            return str;
        }
        */
        /*
        private static byte[] convert_byte(string data)
        {
            byte[] res = new byte[data.Length];
            for (int i = 0; i < data.Length; i++)
            {
                res[i] = (byte)data[i];
            }
            return res;

        }
        */
        /*
        private UInt16 Get_Crc16(string data)
        {
            UInt16 crc16 = 0;
            int data_size = data.Length;
            for (int i = 0; i < data_size; i++)
            {
                int ch = (int)data[i];
                for (int j = 0; j < 8; j++)
                {
                    int b = (crc16 ^ ch) & 1;
                    crc16 >>= 1;
                    ch >>= 1;
                    if (b == 1) crc16 ^= 0xA001;
                }
            }
            return crc16;
        }
        */
        /* 
        private UInt16 to_uint16(byte[] data, int offset)
        {
            UInt16 dd;
            dd = BitConverter.ToUInt16(data, offset);
            return dd;

        }
        */
        /*
        private UInt32 to_uint(byte[] data, int offset)
        {
            uint dd;
            dd = BitConverter.ToUInt32(data, offset);
            return dd;
        }
        private float to_float(byte[] data, int offset)
        {
            float dd = 0f;
            dd = BitConverter.ToSingle(data, offset);
            return dd;
        }
        private string to_string(byte[] data, int offset, int length)
        {
            string str = string.Empty;
            for (int i = offset; i < offset + length; i++)
            {
                str += (char)data[i];
            }
            return str;
        }
        private string cutting_str(string data, int length)
        {
            string str = string.Empty;
            for (int i = 0; i < data.Length - length; i++)
            {
                str += data[i];
            }
            return str;
        }
        */
        #endregion



        public void Set_Up()
        {


            //Serial_Number = RTC6Wrap.n_get_serial_number(Board_Number);
            kFactor= RTC6Wrap.n_get_table_para(Board_Number, 1, 1);
            scalex = (double)(kFactor / 42.57796d);
            //RTC6Wrap.n_set_start_list(Board_Number,10);         
            RTC6Wrap.n_select_cor_table(Board_Number, 1, 0);
            RTC6Wrap.n_set_laser_mode(Board_Number, 1);
            RTC6Wrap.n_set_laser_control(Board_Number, 0);
            RTC6Wrap.n_config_list(Board_Number, 7340032, 1048576);
            RTC6Wrap.n_write_8bit_port(Board_Number, 0);
            RTC6Wrap.n_set_standby(Board_Number, 64, 8);

            //RTC6Wrap.n_set_fly_x(Board_Number, YR.scalex);
            //RTC6Wrap.n_set_end_of_list(Board_Number);
            //RTC6Wrap.n_execute_list(Board_Number,10);

            //Board_Number = 1;
            //Laser_Mode = 1;
            //Laser_Control = 0;
            //MEM1 = 7340032;
            //MEM2 = 1048576;
            //Standby_Pulse_Duration = 64;
            //Standby_Pulse_Width = 8;
            //Kfactor = 0;
        }
        public bool Laser_On()
        {
            UInt32 RTC_Data;

            Thread splashthread = new Thread(new ThreadStart(LoadingLaser.ShowSplashScreen));
            splashthread.IsBackground = true;
            splashthread.Start();

            Thread.Sleep(100);
            LoadingLaser.UpdateStatusText("Turn on Laser Key switch.");

            n_set_bit(Board_Number, Const.Laser_Power_Enable);

            do
            {
                RTC_Data = RTC6Wrap.n_read_io_port(Board_Number);
                RTC_Data &= 0b_0111_1000_0000_0000;


            } while (RTC_Data != 16384);

            LoadingLaser.UpdateStatusText("Laser is turned On.");

            Thread.Sleep(1000);

            Eth.IP_Address = LS_IP_Address;
            Eth.Eth_Connect();
       
            LoadingLaser.CloseSplashScreen();

            return Eth.is_Connected;
        }
        public void Laser_Off()
        {
            //try
            //{
            //Eth.Eth_Disconnect();
            //}
            //catch
            //{
            //MessageBox.Show("Eth not close");
            //}

            Eth.Eth_Disconnect();
            n_Clear_Bit(Board_Number, Const.Laser_Power_Enable);
        }
        public void Get_Serial_Number()
        {
            UInt32 temp_serial = 0;
            temp_serial = RTC6Wrap.n_get_serial_number(Board_Number);
            Serial_Number = temp_serial.ToString();
        }
        public void Set_Laser_Delays()
        {
            RTC6Wrap.n_set_laser_delays(Board_Number,LS_On_Delay, LS_Off_Delay);
        }
        public void Set_Laser_Delays(int ond,UInt32 ofd)
        {
            LS_On_Delay = ond;
            LS_Off_Delay = ofd;
            RTC6Wrap.n_set_laser_delays(Board_Number, ond, ofd);
        }
        public void Set_Scanner_Delays()
        {
            RTC6Wrap.n_set_scanner_delays(Board_Number,Jump_Delay,Cut_Delay,Pol_Delay);
        }
        public void Set_Scanner_Delays(UInt32 jd,UInt32 cd,UInt32 pd)
        {
            Jump_Delay = jd;
            Cut_Delay = cd;
            Pol_Delay = pd;
            RTC6Wrap.n_set_scanner_delays(Board_Number,jd,cd,pd);
        }
        public void Set_Cutting_Speed()
        {
            RTC6Wrap.n_set_mark_speed(Board_Number, Cut_Speed*kFactor);
        }
        public void Set_Cutting_Speed(double cs)
        {
            Cut_Speed = cs;
            RTC6Wrap.n_set_mark_speed(Board_Number, cs * kFactor);
        }
        public void Set_Jump_Speed()
        {
            RTC6Wrap.n_set_mark_speed(Board_Number, Jump_Speed * kFactor);
        }
        public void Set_Jump_Speed(double js)
        {
            Jump_Speed = js;
            RTC6Wrap.n_set_mark_speed(Board_Number, js * kFactor);
        }
        public void Set_Laser_Pulse()
        {
            double temp;
            temp = 1000.0d / Rep_Rate;
            temp *= 32.0d;
            RTC6Wrap.n_set_laser_pulses(Board_Number, (uint)temp, 8);
        }
        public void Set_Laser_Pulse(double rp)
        {
            double temp;
            Rep_Rate = rp;
            temp = 1000.0d / Rep_Rate;
            temp *= 32.0d;
            RTC6Wrap.n_set_laser_pulses(Board_Number, (uint)temp, 8);
        }
        public void Set_Bit(UInt32 bit)
        {
            UInt32 sta = 0;
            sta = RTC6Wrap.n_get_io_status(Board_Number);

            sta = sta | bit;
            RTC6Wrap.n_write_io_port(Board_Number, sta);
        }
        public void Clear_Bit(UInt32 bit)
        {
            UInt32 sta = 0;
            sta = RTC6Wrap.n_get_io_status(Board_Number);

            sta = sta & ~bit;
            RTC6Wrap.n_write_io_port(Board_Number, sta);
        }
        public bool Bit_Check(UInt32 address)
        {
            uint status;
            status = RTC6Wrap.n_read_io_port(Board_Number);
            if ((status & address) == address)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool Out_Bit_Check(UInt32 address)
        {
            uint status;
            status = RTC6Wrap.n_get_io_status(Board_Number);
            if ((status & address) == address)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        /// <summary>
        /// 16bit 해당 RTC 포트에 읽음
        /// </summary>
        /// <param name="data"></param>
        public void Write_IO_Port(UInt32 data)
        {
            RTC6Wrap.n_write_io_port(Board_Number, data);
        }
        public void Write_IO8_Port(UInt32 data)
        {
            RTC6Wrap.n_write_8bit_port(Board_Number, data);
        }
        /// <summary>
        /// RTC 출력 포트에 16bit 데이터를 읽음
        /// </summary>
        /// <returns></returns>
        public UInt32 Get_IO_Port()
        {
            return RTC6Wrap.n_get_io_status(Board_Number);
        }
        public void Set_Offset(int x,int y)
        {
            RTC6Wrap.n_set_offset(Board_Number, 1, x, y, 0);
        }
        public void Set_Angle(double an)
        {
            RTC6Wrap.n_set_angle(Board_Number, 1, an, 0);
        }
        public void Set_Start_List(UInt32 List_Num)
        {
            RTC6Wrap.n_set_start_list(Board_Number, List_Num);
        }
        public void Set_End_of_List()
        {
            RTC6Wrap.n_set_end_of_list(Board_Number);
        }
        public void Excute_List(UInt32 List_Num)
        {
            RTC6Wrap.n_execute_list(Board_Number, List_Num);
        }
        public void Set_Control_Mode(uint data)
        {
            RTC6Wrap.n_set_control_mode(Board_Number, data);
        }
        public uint Get_IO_Status()
        {
            return RTC6Wrap.n_get_io_status(Board_Number);
        }
        public uint Read_IO_Port()
        {
            return RTC6Wrap.n_read_io_port(Board_Number);
        }
        public double Get_Time()
        {
            uint Status, Pos;
            double time;

            do
            {
                RTC6Wrap.n_get_status(Board_Number, out Status, out Pos);
            } while ((Status & 0b_0000_0000_0000_0001) == 0b_0000_0000_0000_0001);

            
            time = RTC6Wrap.n_get_time(Board_Number);

            return time;
        }
        public void Data_Download_STA(LS_WF.WF data)
        {
            int i;
            PointF SP = new PointF();   //SP as a start point perpose
            float diff = 0f;            //distance check from startpoint and previous endpoint
            bool cc1 = true; //for checking connected or not
            LS_WF.JOB job = new LS_WF.JOB(); //temporary job 
            Init_Condition I_Cond = new Init_Condition();

            if (data.DD.Count == 0)
            {
                MessageBox.Show("There is Cutting line data to download.");
                RTC6Wrap.n_set_start_list(Board_Number, 5);
                RTC6Wrap.n_write_8bit_port(Board_Number, 0);
                RTC6Wrap.n_set_end_of_list(Board_Number);
                RTC6Wrap.n_execute_list(Board_Number,5);
            }
            else if (data.DD[0].Name == "Default")
            {
                MessageBox.Show("There is Cutting line data to download.");
                RTC6Wrap.n_set_start_list(Board_Number, 5);
                RTC6Wrap.n_write_8bit_port(Board_Number, 0);
                RTC6Wrap.n_set_end_of_list(Board_Number);
                RTC6Wrap.n_execute_list(Board_Number, 5);
            }
            else
            {
                //insert WF1 startpoint to SP
                switch (data.DD[0].Name)
                {
                    case "LINE":
                        SP = data.DD[0].Data_0;
                        break;
                    case "ARC":
                        SP = Find_ARC_Start(data.DD[0]);
                        break;
                    default:
                        break;
                }

                double cutting_speed = 0, rep_rate = 0;
                uint laser_power = 0;

                //Jump_Speed 5m/s;

                RTC6Wrap.n_set_start_list(Board_Number, 2);
                RTC6Wrap.n_save_and_restart_timer(Board_Number);   //rtc timer reset ot 0
                
                ///필요하다면 수정필요 20240411
                RTC6Wrap.n_set_jump_speed(Board_Number, 10.0d * kFactor);
                
                
                //RTC6Wrap.n_set_io_cond_list(Board_Number, 0, 0, Const.B_Busy); //busy out
                cutting_speed = (double)data.Ls_Parameters[data.DD[0].C_Index].M_Speed;
                laser_power = Convert.ToUInt32(data.Ls_Parameters[data.DD[0].C_Index].Ls_Power*2.55);
                rep_rate = data.Ls_Parameters[data.DD[0].C_Index].Rep_rate;


                RTC6Wrap.n_set_mark_speed(Board_Number, cutting_speed * kFactor);
                RTC6Wrap.n_write_8bit_port(Board_Number, laser_power);
                n_Set_Laser_Pulse(Board_Number, rep_rate);
                n_Jump_Abs(Board_Number, SP, kFactor);

                for (i = 0; i < data.DD.Count; i++)
                {
                    cc1 = true;
                    if (cutting_speed != data.Ls_Parameters[data.DD[i].C_Index].M_Speed)
                    {
                        cutting_speed = data.Ls_Parameters[data.DD[i].C_Index].M_Speed;
                        RTC6Wrap.n_set_mark_speed(Board_Number, cutting_speed * kFactor);
                    }

                    if (laser_power != data.Ls_Parameters[data.DD[i].C_Index].Ls_Power)
                    {
                        laser_power = Convert.ToUInt32(data.Ls_Parameters[data.DD[i].C_Index].Ls_Power*2.55);
                        
                        RTC6Wrap.n_write_8bit_port(Board_Number, laser_power);
                    }

                    if (rep_rate != data.Ls_Parameters[data.DD[i].C_Index].Rep_rate)
                    {
                        rep_rate = data.Ls_Parameters[data.DD[i].C_Index].Rep_rate;
                        n_Set_Laser_Pulse(Board_Number, rep_rate);
                    }


                    switch (data.DD[i].Name)
                    {
                        case "LINE":

                            diff = Math.Abs(SP.X - data.DD[i].Data_0.X);
                            if (diff > 0.020f)
                            {
                                cc1 = false;
                            }

                            if (cc1 == true)
                            {
                                diff = Math.Abs(SP.Y - data.DD[i].Data_0.Y);
                                if (diff > 0.020f)
                                {
                                    cc1 = false;
                                }
                            }

                            if (cc1)
                            {
                                RTC6Wrap.n_mark_abs(Board_Number, (int)(data.DD[i].Data_1.X * kFactor), (int)(data.DD[i].Data_1.Y * kFactor));
                            }
                            else
                            {
                                n_Jump_Abs(Board_Number, data.DD[i].Data_0, kFactor);
                                RTC6Wrap.n_mark_abs(Board_Number, (int)(data.DD[i].Data_1.X * kFactor), (int)(data.DD[i].Data_1.Y * kFactor));
                            }
                            SP = data.DD[i].Data_1;
                            break;
                        case "ARC":
                            //test 용   

                            diff = Math.Abs(SP.X - Find_ARC_Start(data.DD[i]).X);
                            if (diff > 0.020f) cc1 = false;
                            if (cc1 == true)
                            {
                                diff = Math.Abs(SP.Y - Find_ARC_Start(data.DD[i]).Y);
                                if (diff > 0.020f) cc1 = false;
                            }


                            if (cc1)
                            {
                                n_Arc_Abs(Board_Number, data.DD[i].Data_0, (double)data.DD[i].FD_2, kFactor);
                            }
                            else
                            {
                                n_Jump_Abs(Board_Number, Find_ARC_Start(data.DD[i]), kFactor);
                                n_Arc_Abs(Board_Number, data.DD[i].Data_0, (double)data.DD[i].FD_2, kFactor);

                            }

                            SP = Find_ARC_End(data.DD[i]);
                            break;
                        default:
                            break;
                    }
                }
            }
            // board 1  turn off busy
            //RTC6Wrap.n_clear_io_cond_list(Board_Number, 0, 0, Const.B_Busy);
            //타이머 리셋
            RTC6Wrap.n_save_and_restart_timer(Board_Number);

            /*
            switch (data.DD[0].Name)
            {
                case "LINE":
                    SP = data.DD[0].Data_0;
                    break;
                case "ARC":
                    SP = Find_ARC_Start(data.DD[0]);
                    break;
                default:
                    break;
            }
            */
            n_Jump_Abs(Board_Number, SP, kFactor);

            RTC6Wrap.n_set_end_of_list(Board_Number);
        }
        public void Data_Download_FLY(LS_WF.WF data)
        {
            int i;
            //uint Status, Pos;
            
            float diff = 0f;            //distance check from startpoint and previous endpoint
            bool cc1 = true; //for checking connected or not
            LS_WF.JOB job = new LS_WF.JOB(); //temporary job
            PointF temp_data = new PointF(); 

           
            //로드된 데이터가 없는경우 power =0 으로 하기 위한 루틴 
            if (data.DD.Count == 0)
            {
                //MessageBox.Show("There is Cutting line data to download.");
                RTC6Wrap.n_set_start_list(Board_Number, 5);
                RTC6Wrap.n_write_8bit_port(Board_Number, 0);
                RTC6Wrap.n_set_end_of_list(Board_Number);
                RTC6Wrap.n_execute_list(Board_Number, 5);
            }
            else if (data.DD[0].Name == "Default")
            {
                //MessageBox.Show("There is Cutting line data to download.");
                RTC6Wrap.n_set_start_list(Board_Number, 5);
                RTC6Wrap.n_write_8bit_port(Board_Number, 0);
                RTC6Wrap.n_set_end_of_list(Board_Number);
                RTC6Wrap.n_execute_list(Board_Number, 5);
            }
            else
            {
                //insert WF1 startpoint to SP
                switch (data.DD[0].Name)
                {
                    case "LINE":

                        temp_data.X = data.DD[0].Data_0.X + MOF_Offset_X; 
                        temp_data.Y = data.DD[0].Data_0.Y + MOF_Offset_Y;
                        SP = temp_data;
                        break;
                    case "ARC":
                        temp_data= Find_ARC_Start(data.DD[0]); 
                        temp_data.X += MOF_Offset_X;
                        temp_data.Y += MOF_Offset_Y;
                        SP= temp_data; 
                        break;
                    default:
                        break;
                }

                double cutting_speed = 0, rep_rate = 0;
                uint laser_power = 0;

                //Jump_Speed 5m/s;

                RTC6Wrap.n_set_start_list(Board_Number, 1);
                RTC6Wrap.n_save_and_restart_timer(Board_Number);   //rtc timer reset ot 0
                RTC6Wrap.n_set_jump_speed(Board_Number, 10.0 * kFactor);
                // n_set_io_cond_list should be board 1
                //RTC6Wrap.n_set_io_cond_list(Board_Number, 0, 0, Const.B_Busy); //busy out
                cutting_speed = (double)data.Ls_Parameters[data.DD[0].C_Index].M_Speed;
                laser_power = Convert.ToUInt32(data.Ls_Parameters[data.DD[0].C_Index].Ls_Power*2.55);
                rep_rate = data.Ls_Parameters[data.DD[0].C_Index].Rep_rate;


                RTC6Wrap.n_set_mark_speed(Board_Number, cutting_speed * kFactor);
                RTC6Wrap.n_write_8bit_port(Board_Number, laser_power);
                n_Set_Laser_Pulse(Board_Number, rep_rate);

                n_Jump_Abs(Board_Number, SP, kFactor);

                scalex = (double)(kFactor / 4000 * 96.2);

                ////////////////////////////////////////////////////////////////////////////////////////////
                //RTC6Wrap.n_activate_fly_1_axis(Board_Number, 1, 1, scalex, 0);

                RTC6Wrap.n_set_fly_x(Board_Number, scalex);
                //RTC6Wrap.n_set_fly_y(Board_Number, scalex);

                for (i = 0; i < data.DD.Count; i++)
                {
                    cc1 = true; 
                    //커팅 스피드가 전 데이터와 다르면 새로운 커팅 스피드 셋
                    if (cutting_speed != data.Ls_Parameters[data.DD[i].C_Index].M_Speed) 
                    {
                        cutting_speed = data.Ls_Parameters[data.DD[i].C_Index].M_Speed; 
                        RTC6Wrap.n_set_mark_speed(Board_Number, cutting_speed * kFactor); 
                    }

                    //레이저 파워가 전 데이터와 다르면 새로운 레이저 파워 셋
                    if (laser_power != data.Ls_Parameters[data.DD[i].C_Index].Ls_Power) 
                    {
                        laser_power = Convert.ToUInt32(data.Ls_Parameters[data.DD[i].C_Index].Ls_Power*2.55);
                        RTC6Wrap.n_write_8bit_port(Board_Number, laser_power);
                    }

                    //반복률이 전 데이터 와 다르면 새로운 반복률 셋
                    if (rep_rate != data.Ls_Parameters[data.DD[i].C_Index].Rep_rate) 
                    {
                        rep_rate = data.Ls_Parameters[data.DD[i].C_Index].Rep_rate;
                        n_Set_Laser_Pulse(Board_Number, rep_rate);
                    }

                    switch (data.DD[i].Name)
                    {
                        case "LINE":

                            diff = Math.Abs(SP.X - (data.DD[i].Data_0.X+MOF_Offset_X)); 
                            if (diff > 0.020f) 
                            {
                                cc1 = false;
                            }

                            if (cc1 == true) 
                            {
                                diff = Math.Abs(SP.Y - (data.DD[i].Data_0.Y+MOF_Offset_Y));
                                if (diff > 0.020f) 
                                {
                                    cc1 = false;
                                }
                            }

                            if (cc1)
                            {
                                RTC6Wrap.n_mark_abs(Board_Number, (int)((data.DD[i].Data_1.X + MOF_Offset_X) * kFactor), (int)((data.DD[i].Data_1.Y + MOF_Offset_Y) * kFactor));
                            }
                            else
                            {
                                temp_data.X = data.DD[i].Data_0.X + MOF_Offset_X; 
                                temp_data.Y = data.DD[i].Data_0.Y + MOF_Offset_Y; 
                                n_Jump_Abs(Board_Number, temp_data, kFactor); 
                                RTC6Wrap.n_mark_abs(Board_Number, (int)((data.DD[i].Data_1.X+MOF_Offset_X) * kFactor), (int)((data.DD[i].Data_1.Y+MOF_Offset_Y) * kFactor)); 
                            }
                            temp_data.X = data.DD[i].Data_1.X + MOF_Offset_X;
                            temp_data.Y = data.DD[i].Data_1.Y + MOF_Offset_Y;
                            SP = temp_data;
                            break;
                        case "ARC":
                            //test 용   

                            diff = Math.Abs(SP.X - (Find_ARC_Start(data.DD[i]).X + MOF_Offset_X));
                            if (diff > 0.020f) cc1 = false;
                            if (cc1 == true)
                            {
                                diff = Math.Abs(SP.Y - (Find_ARC_Start(data.DD[i]).Y + MOF_Offset_Y));
                                if (diff > 0.020f) cc1 = false;
                            }


                            if (cc1)
                            {
                                temp_data.X = data.DD[i].Data_0.X + MOF_Offset_X;
                                temp_data.Y = data.DD[i].Data_0.Y + MOF_Offset_Y;
                                n_Arc_Abs(Board_Number, temp_data, (double)data.DD[i].FD_2, kFactor);
                            }
                            else
                            {
                                temp_data = Find_ARC_Start(data.DD[i]);
                                temp_data.X += MOF_Offset_X;
                                temp_data.Y += MOF_Offset_Y;
                                n_Jump_Abs(Board_Number,temp_data, kFactor);
                                temp_data.X = data.DD[i].Data_0.X + MOF_Offset_X;
                                temp_data.Y = data.DD[i].Data_0.Y + MOF_Offset_Y;
                                n_Arc_Abs(Board_Number, temp_data, (double)data.DD[i].FD_2, kFactor);

                            }
                            temp_data = Find_ARC_End(data.DD[i]);
                            temp_data.X += MOF_Offset_X;
                            temp_data.Y += MOF_Offset_Y;
                            SP = temp_data;
                            break;
                        default:
                            break;
                    }
                }
            }


            // board 1  turn off busy
            //RTC6Wrap.n_clear_io_cond_list(Board_Number, 0, 0, Const.B_Busy);
            //타이머 리셋


            switch (data.DD[0].Name) 
            {
                case "LINE":
                    temp_data.X = data.DD[0].Data_0.X + MOF_Offset_X;
                    temp_data.Y = data.DD[0].Data_0.Y + MOF_Offset_Y;
                    SP = temp_data;
                    break;
                case "ARC":
                    temp_data = Find_ARC_Start(data.DD[0]);
                    temp_data.X += MOF_Offset_X;
                    temp_data.Y += MOF_Offset_Y;
                    SP= temp_data;

                    break;
                default:
                    break;
            }

           

            RTC6Wrap.n_fly_return(Board_Number, (int)(SP.X * kFactor), (int)(SP.Y * kFactor));
            //n_Jump_Abs(Board_Number, SP,kFactor);
            RTC6Wrap.n_set_end_of_list(Board_Number);
            RTC6Wrap.n_save_and_restart_timer(Board_Number); 
            
        }
        public void Stop_Eccution()
        {
            RTC6Wrap.n_stop_execution(Board_Number);
        }

        public void Set_Power(uint power)
        {
            RTC6Wrap.n_write_8bit_port(Board_Number, power);
        }

        public void Data_Area_Check(LS_WF.WF data)
        {
            if ((data.DD.Count == 0) || (data.DD[0].Selected))
            {
                MessageBox.Show("영역확인을 위한 전극도면이 로드되지 않았습니다.");
            }

            else
            {
                PointF SP = new PointF();
                //        PointF TP = new PointF();

                switch (data.DD[0].Name)   //시작점으로 이동
                {
                    case "LINE":
                        SP = data.DD[0].Data_0;
                        break;
                    case "ARC":
                        SP = Find_ARC_Start(data.DD[0]);
                        break;
                    default:
                        break;
                }

                RTC6Wrap.n_set_start_list(Board_Number, 4);

                RTC6Wrap.n_set_jump_speed(Board_Number, (double)(5 * kFactor));  // 우선 테스트 라서 3m/sec 으로 설정;
                RTC6Wrap.n_set_mark_speed(Board_Number, (double)(5 * kFactor));  // 테스트라서 3m/sec;
                RTC6Wrap.n_write_8bit_port(Board_Number, 0); // 레이저 파워 0 으로 세팅

                RTC6Wrap.n_list_repeat(Board_Number);


                n_Jump_Abs(Board_Number, SP, kFactor);

                for (int i = 0; i < data.DD.Count; i++)
                {
                    switch (data.DD[i].Name)
                    {
                        case "LINE":
                            if (SP == data.DD[i].Data_0)
                            {
                                RTC6Wrap.n_mark_abs(Board_Number, (int)(data.DD[i].Data_1.X * kFactor), (int)(data.DD[i].Data_1.Y * kFactor));
                            }
                            else
                            {
                                n_Jump_Abs(Board_Number, data.DD[i].Data_0, kFactor);
                                RTC6Wrap.n_mark_abs(Board_Number, (int)(data.DD[i].Data_1.X * kFactor), (int)(data.DD[i].Data_1.Y * kFactor));
                            }
                            SP = data.DD[i].Data_1;
                            break;
                        case "ARC":
                            //                           TP = Find_ARC_Start(WF[i]);
                            if (SP == Find_ARC_Start(data.DD[i]))
                            {
                                n_Arc_Abs(Board_Number, data.DD[i].Data_0, (double)data.DD[i].FD_2, kFactor); 
                            }
                            else
                            {
                                n_Jump_Abs(Board_Number, Find_ARC_Start(data.DD[i]), kFactor);
                                n_Arc_Abs(Board_Number, data.DD[i].Data_0, (double)data.DD[i].FD_2,kFactor);
                            }
                            SP = Find_ARC_End(data.DD[i]);
                            break;
                        default:
                            break;
                    }
                }

                RTC6Wrap.n_list_until(Board_Number, 50000);
                RTC6Wrap.n_set_end_of_list(Board_Number);
                

            }
        }

        #region Functions
        private void n_set_bit(UInt32 board, UInt32 bit)
        {
            UInt32 sta = 0;
            sta = RTC6Wrap.n_get_io_status(board);

            sta = sta | bit;
            RTC6Wrap.n_write_io_port(board, sta);
        }
        private void n_Clear_Bit(UInt32 board, UInt32 bit)
        {
            UInt32 sta = 0;
            sta = RTC6Wrap.n_get_io_status(board);

            sta = sta & ~bit;
            RTC6Wrap.n_write_io_port(board, sta);
        }
        private bool n_Bit_Check(UInt32 board, UInt32 address)
        {
            uint status;
            status = RTC6Wrap.n_read_io_port(board);
            if ((status & address) == address)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private bool n_Out_Bit_Check(UInt32 board, UInt32 address)
        {
            uint status;
            status = RTC6Wrap.n_get_io_status(board);
            if ((status & address) == address)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private PointF Find_ARC_Start(LS_WF.JOB target)
        {
            PointF cord = new PointF();
            double r_angle;
            r_angle = (double)target.FD_1;
            cord.X = target.Data_0.X + (float)(Math.Cos(r_angle) * target.FD_0);
            cord.Y = target.Data_0.Y - (float)(Math.Sin(r_angle) * target.FD_0);
            return cord;
        }
        private PointF Find_ARC_End(LS_WF.JOB target)
        {
            PointF cord = new PointF();
            double r_angle;
            r_angle = (double)(target.FD_1 + target.FD_2);
            cord.X = target.Data_0.X + (float)(Math.Cos(r_angle) * target.FD_0);
            cord.Y = target.Data_0.Y - (float)(Math.Sin(r_angle) * target.FD_0);
            return cord;
        }
        private void n_Set_Laser_Pulse(UInt32 Board_Number, double rep_rate)
        {
            double temp;
            temp = 1000.0 / rep_rate;
            temp *= 32;
            RTC6Wrap.n_set_laser_pulses(Board_Number, (uint)temp, 8);
        }
        private void n_Jump_Abs(UInt32 Board_Number, PointF target, double kfactor)
        {
            RTC6Wrap.n_jump_abs(Board_Number, (int)(target.X * kfactor), (int)(target.Y * kfactor));
        }
        private void n_Arc_Abs(UInt32 Board_Number, PointF center, double angle, double kfactor)
        {
            double r_angle;
            r_angle = angle * 180.0 / Math.PI;
            RTC6Wrap.n_arc_abs(Board_Number, (int)(center.X * kfactor), (int)(center.Y * kfactor), r_angle);
        }
        public LS_WF.JOB Li_Info(LS_WF.JOB job, Point Loc)
        {
            double length;
            double angle;
            Line_Info f2 = new Line_Info();

            f2.Start_X = job.Data_0.X;
            f2.Start_Y = job.Data_0.Y;
            f2.End_X = job.Data_1.X;
            f2.End_Y = job.Data_1.Y;

            f2.Parameter_Index = job.C_Index;

            length = Math.Sqrt((double)((job.Data_0.X - job.Data_1.X) * (job.Data_0.X - job.Data_1.X) + (job.Data_0.Y - job.Data_1.Y) * (job.Data_0.Y - job.Data_1.Y)));
            f2.Length = (float)length;

            angle = Math.Atan2((double)(job.Data_1.Y - job.Data_0.Y), (double)(job.Data_1.X - job.Data_0.X));
            angle *= (180 / Math.PI);
            f2.Angle = (float)angle;

            f2.StartPosition = FormStartPosition.Manual;
            f2.Location = new Point(Loc.X, Loc.Y);
            f2.ShowDialog();
            if (f2.DialogResult == DialogResult.OK)
            {
                job.Data_0 = new PointF(f2.Start_X, f2.Start_Y);
                job.Data_1 = new PointF(f2.End_X, f2.End_Y);

                job.C_Index = f2.Parameter_Index;
            }
            f2.Dispose();

            return job;
        }
        public LS_WF.JOB Arc_Info(LS_WF.JOB job, Point Loc)
        {

            ARC_Info f4 = new ARC_Info();
            f4.Center_X = job.Data_0.X;
            f4.Center_Y = job.Data_0.Y;
            f4.Radius = job.FD_0;
            f4.Start_Angle = job.FD_1;
            f4.Sweep_Angle = job.FD_2;
            f4.Parameter_Index = job.C_Index;

            //창이 나타나는 위치조정을 위한 코드

            f4.StartPosition = FormStartPosition.Manual;
            f4.Location = new Point(Loc.X, Loc.Y);

            f4.ShowDialog();
            if (f4.DialogResult == DialogResult.OK)
            {
                job.Data_0 = new PointF(f4.Center_X, f4.Center_Y);
                job.FD_0 = f4.Radius;
                job.FD_1 = f4.Start_Angle;
                job.FD_2 = f4.Sweep_Angle;

                job.C_Index = f4.Parameter_Index;


            }
            f4.Dispose();
            return job;

        }
        #endregion
    }

    public class LS_WF
    {
        [Serializable]
        public class WF
        {
            public List<JOB> DD = new List<JOB>();
            public Ls_Parameter[] Ls_Parameters = new Ls_Parameter[4];
            //public List<Ls_Parameter> Ls_Parameters = new List<Ls_Parameter>();
            public WF()
            {
                Ls_Parameters[0] = new Ls_Parameter();
                Ls_Parameters[1] = new Ls_Parameter();
                Ls_Parameters[2] = new Ls_Parameter();
                Ls_Parameters[3] = new Ls_Parameter();
            
                //DD.Add(new JOB());
            }
            ~WF() { }
        }

        [Serializable]
        public class JOB
        {
            public PointF Data_0 { get; set; }  //LINE object 인경우 시작점 ARC object인 경우 중심점
            public PointF Data_1 { get; set; }  //LINE 인경우 끝점 ARC 인경우 사용안함
            public float FD_0 { get; set; }  
            public float FD_1 { get; set; }
            public float FD_2 { get; set; }
            public string Name { get; set; }
            public byte C_Index { get; set; }
            public bool Selected { get; set; }


            public JOB()
            {
                Data_0 = new PointF(0f, 0f);
                Data_1 = new PointF(0f, 0f);
                FD_0 = 1;
                FD_1 = 0;
                FD_2 = (float)Math.PI;
                Name = "Default";
                C_Index = 0;
                Selected = false;
            }

            ~JOB() { }
        }

        [Serializable]
        public class Ls_Parameter
        {

            public byte Ls_Power { get; set; }
            public float M_Speed { get; set; }
            public float Rep_rate { get; set; }
           
            public Ls_Parameter()
            {
                Ls_Power = 0;
                M_Speed = 1;
                Rep_rate = 500;
                
            }

            ~Ls_Parameter() { }

        }
    }
    public class SV_Delay
    {
        public SV_Delay()
        {
            //S1_Delay = 2323;
            //S2_Delay = 24242;
        }
        public int S1_Delay { get; set; }
        public int S2_Delay { get; set; }
        public string SV_Delay_File { get; set; }
        ~SV_Delay() { }

    }

    public class MOF_Offset
    {
        public MOF_Offset()
        {
            Front_Offset_X = (float)0.0;
            Front_Offset_Y = (float)0.0;
            Back_Offset_X = (float)0.0;
            Back_Offset_Y = (float)0.0;

        }
        public float Front_Offset_X { get; set; }
        public float Front_Offset_Y { get; set; }
        public float Back_Offset_X { get; set; }
        public float Back_Offset_Y { get; set; }
        public string Mof_Offset_File { get; set; }
        ~MOF_Offset() { }
    }
    /// <summary>
    /// 초기 조건을 저장하는 클래스
    /// </summary>
    public class Init_Condition
    {
        public Init_Condition()
        {
            Jump_Speed1 = 5;
            Jump_Speed2 = 5;
        }

        public string Pre_File_Name { get; set; }   // 카메라 관련 변수
        public string Init_File_Path { get; set; }
        public PointF Initial_Offset1 { get; set; }
        public PointF Initial_Offset2 { get; set; }
        public double Initial_Angle1 { get; set; }
        public double Initial_Angle2 { get; set; }
        public int LS_On_Delay1 { get; set; }
        public int LS_On_Delay2 { get; set; }
        public uint LS_Off_Delay1 { get; set; }
        public uint LS_Off_Delay2 { get; set; }
        public uint LS_Cut_Delay1 { get; set; }
        public uint LS_Cut_Delay2 { get; set; }
        public uint LS_Jump_Delay1 { get; set; }
        public uint LS_Jump_Delay2 { get; set; }
        public uint LS_Polygon_Delay1 { get; set; }
        public uint LS_Polygon_Delay2 { get; set; }
        public float Jump_Speed1 { get; set; }
        public float Jump_Speed2 { get; set; }
        ~Init_Condition() { }
    }
       
}
