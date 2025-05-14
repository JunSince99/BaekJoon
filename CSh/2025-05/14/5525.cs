using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();

        int count = 0;
        int result = 0;
        int i = 1;

        while (i < m - 1)
        {
            if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
            {
                count++;
                if (count == n)
                {
                    result++;
                    count--;
                }
                i += 2;
            }
            else
            {
                count = 0;
                i++;
            }
        }

        Console.WriteLine(result);
    }
}