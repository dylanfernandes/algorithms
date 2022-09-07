using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'viralAdvertising' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER n as parameter.
     */

    public static int viralAdvertising(int n)
    {
        int day = n;
        int numLikes = 0;
        int peopleShared = 0;
        if(n == 0)
            return numLikes;
        while(day > 0) 
        {
            if(day == n) 
            {
                peopleShared = 5;
            } 
            else 
            {
                peopleShared = (int)Math.Floor((double)peopleShared/2) * 3;    
            }
            
            numLikes += (int)Math.Floor((double)peopleShared/2);
            day--;
        }
        
        return numLikes;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        int result = Result.viralAdvertising(n);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
