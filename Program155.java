import java.util.*;

class Arithematic
{
    public int Addition(int iValue1, int iValue2)
    {
        int iSum = 0;
        iSum = iValue1 + iValue2;
        return iSum;
    }
}

class Program155
{
    public static void main(String Arg[])
    {
        Arithematic aboj = new Arithematic();
        Scanner sobj = new Scanner(System.in);

        int iNo1 = 0, iNo2 = 0;
        int iAns = 0;

        System.out.println("Enter First number : ");
        iNo1 = sobj.nextInt();

        System.out.println("Enter Second number : ");
        iNo2 = sobj.nextInt();

        iAns = aboj.Addition(iNo1,iNo2);
        System.out.println("Addition is : "+iAns);
    }
}