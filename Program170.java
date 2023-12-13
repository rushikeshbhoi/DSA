import java.util.*;

class Program170
{
    public static void Display(String str)
    {
        int iCnt = 0;
        char Arr[] = str.toCharArray();
        for(iCnt = 0; iCnt < Arr.length; iCnt++)
        {
            System.out.println(Arr[iCnt]);
        }
    }
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter your name : ");
        str = sobj.nextLine();

        int iCnt = 0;

        for(iCnt = 0; iCnt < str.length(); iCnt++)
        {
            System.out.println(str.charAt(iCnt));
        }

        sobj.close();
    }
}

