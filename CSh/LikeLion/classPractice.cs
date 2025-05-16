using System;
using System.Collections.Generic;


class Player
{
    public string name = "";
    public int level = 1;
    public int maxLevel = 10;

    public Player(string name, int level)
    {
        this.name = name;
        this.level = level;

        Console.WriteLine($"캐릭터 : {name}, 레벨 : {level} 생성완료");
    }

    public void LevelUp()
    {
        if (level < maxLevel)
        {
            level++;
            Console.WriteLine($"{name} 캐릭터 레벨 업!!, 현재 레벨{level}");
        }
        else
        {
            Console.WriteLine($"{name} 캐릭터는 이미 최대 레벨입니다.");
        }
    }
}

internal class Program
{
    static void Main(string[] args)
    {
        List<Player> playerList = new List<Player>();

        for (int i = 0; i < 5; i++)
        {
            string playerName = $"Gamer{i + 1}";
            int level = 1;

            Player player = new Player(playerName, level);
            playerList.Add(player);
        }

        Console.WriteLine($"현재 플레이어 리스트의 길이는 {playerList.Count} 입니다.");
    }
}