import java.util.*;

class Program151
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo1 = 0, iNo2 = 0;
        int iAns = 0;

        System.out.println("Enter First number : ");
        iNo1 = sobj.nextInt();

        System.out.println("Enter Second number : ");
        iNo2 = sobj.nextInt();

        iAns = iNo1 + iNo2;
        System.out.println("Addition is : "+iAns);
    }
}