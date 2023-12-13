import java.util.*;

class Arithematic
{
    public int iValue1;
    public int iValue2;
    
    public Arithematic(int A, int B)
    {
        this.iValue1 = A;
        this.iValue2 = B;
    }

    public int Addition()
    {
        int iSum = 0;
        iSum = this.iValue1 + this.iValue2;
        return iSum;
    }
}

class Program156
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

        Arithematic aboj = new Arithematic(iNo1,iNo2);

        iAns = aboj.Addition();
        System.out.println("Addition is : "+iAns);
    }
}