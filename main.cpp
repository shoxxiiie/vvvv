using System;

class Program
{
    static void Main()
    {
        int[] A = new int[5];
        double[,] B = new double[3, 4];
        
        for (int i = 0; i < A.Length; i++) A[i] = int.Parse(Console.ReadLine());
        
        Random rnd = new Random();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                B[i, j] = rnd.NextDouble() * 100;
        
        foreach (int num in A) Console.Write(num + " ");
        Console.WriteLine();
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
                Console.Write(B[i, j] + " ");
            Console.WriteLine();
        }

        int[,] matrix = new int[5, 5];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                matrix[i, j] = rnd.Next(-100, 101);
        
        int min = matrix[0, 0], max = matrix[0, 0], sum = 0;
        foreach (var item in matrix)
        {
            if (item < min) min = item;
            if (item > max) max = item;
        }
        bool between = false;
        foreach (var item in matrix)
        {
            if (item == min || item == max) between = !between;
            else if (between) sum += item;
        }
        Console.WriteLine(sum);

        string text = Console.ReadLine();
        int shift = 3;
        char[] encryptedArray = new char[text.Length];
        for (int i = 0; i < text.Length; i++) encryptedArray[i] = (char)(text[i] + shift);
        string encrypted = new string(encryptedArray);
        
        char[] decryptedArray = new char[encrypted.Length];
        for (int i = 0; i < encrypted.Length; i++) decryptedArray[i] = (char)(encrypted[i] - shift);
        string decrypted = new string(decryptedArray);
        
        Console.WriteLine(encrypted);
        Console.WriteLine(decrypted);

        int[,] matrix1 = new int[2, 2], matrix2 = new int[2, 2], result = new int[2, 2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                matrix1[i, j] = rnd.Next(1, 10);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                matrix2[i, j] = rnd.Next(1, 10);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    result[i, j] += matrix1[i, k] * matrix2[k, j];
        
        string inputText = Console.ReadLine();
        string[] sentences = inputText.Split(new string[] { ". " }, StringSplitOptions.None);
        for (int i = 0; i < sentences.Length; i++)
            if (sentences[i].Length > 0)
                sentences[i] = char.ToUpper(sentences[i][0]) + sentences[i].Substring(1);
        Console.WriteLine(string.Join(". ", sentences));
    }
}
