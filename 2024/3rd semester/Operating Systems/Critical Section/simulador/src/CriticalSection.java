//
// Seção Critica - Fernanda Martins da Silva bv3032345
//

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CriticalSection {

    private static final Lock lock = new ReentrantLock();

    public static void main(String[] args) {
        for (int i = 1; i <= 3; i++) {
            Thread thread = new Thread(new FileWritingTask(i, lock));
            thread.start();
        }
    }
}

class FileWritingTask implements Runnable {

    private int threadId;
    private int writeCount = 0;
    private static final int MAX_WRITES = 10;
    private final Lock lock;

    public FileWritingTask(int threadId, Lock lock){
        this.threadId = threadId;
        this.lock = lock;
    }

    @Override
    public void run(){
        Random random = new Random();

        while(writeCount < MAX_WRITES){
            try{
                Thread.sleep(random.nextInt(6000) + 5000);

                boolean acquired = lock.tryLock();
                if(acquired){
                    try{
                        if(writeCount >= MAX_WRITES){
                            break;
                        }

                        System.out.println("Thread " + threadId + " abriu o arquivo");
                        writeToFile();
                        writeCount += 3;

                        if(writeCount > MAX_WRITES){
                            writeCount = MAX_WRITES;
                        }

                        System.out.println("Thread " + threadId + " fechou o arquivo");

                    }finally{
                        lock.unlock();
                    }
                }else{
                    System.out.println("Thread " + threadId + " tentou acessar o arquivo sem sucesso");
                }

            }catch (InterruptedException e){
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("Thread " + threadId + " terminou após escrever " + writeCount + " linhas.");
    }

    private void writeToFile(){
        try(FileWriter writer = new FileWriter("secaocritica.txt", true)){
            if(writeCount < MAX_WRITES){
                writer.write("Thread " + threadId + ": Linha " + (writeCount + 1) + " escrita (aguardar 1 seg)\n");
                writer.flush();
                Thread.sleep(1000);

                if(writeCount + 1 < MAX_WRITES){
                    writer.write("Thread " + threadId + ": Linha " + (writeCount + 2) + " escrita (aguardar 1 seg)\n");
                    writer.flush();
                    Thread.sleep(1000);

                    if(writeCount + 2 < MAX_WRITES){
                        writer.write("Thread " + threadId + ": Linha " + (writeCount + 3) + " escrita (aguardar 1 seg / Fechar Arquivo)\n");
                        writer.flush();
                        Thread.sleep(1000);
                    }
                }
            }
        }catch(IOException | InterruptedException e){
            e.printStackTrace();
        }
    }
}
