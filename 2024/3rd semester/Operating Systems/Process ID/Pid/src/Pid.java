/*
* 
* @author FernandaDesktop
* 
*/

import java.io.IOException;

public class Pid{
    public static void main(String[] args) {
        if(args.length == 0){
            Long pidatual = ProcessHandle.current().pid();
            System.out.println(pidatual);
        }else{
            try{
                Process p= new ProcessBuilder(args[0]).start();
                long inpid = p.pid();
                System.out.println(inpid);
            }catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}