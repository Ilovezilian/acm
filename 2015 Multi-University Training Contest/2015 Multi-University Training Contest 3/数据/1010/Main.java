import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
public static void main(String [] args){
    int cas = 1;
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext()){
        System.out.println("Case "+cas+":");
        cas ++;
        BigerInteger A = cin.nextBigerInteger(), B = cin.nextBigerInteger();
        System.out.println(A + " + " + B + " = " + A.add(B));
        if(cas != 1) System.out.println("");
    }
}
}
