import java.io.*;
import java.io.File;

public class mergeTransactions{
  public static void main(String args[]) throws IOException{
      //To check if file exists to exit loop
  int existance=0;
  //Iterates next counter
  int counter=0;
  //Loads the file path and current line within the file
  String filepath,strCurrentLine;
  //Used to check and call Writers/Readers
  File inpf,outf;

  outf=new File("mergedTransactionFile.txt");
  filepath="dailyTransactionFile" + counter + ".txt";
  inpf=new File(filepath);
  //Reader and Writers
  BufferedReader br = new BufferedReader(new FileReader(filepath));
  FileWriter fr = new FileWriter("mergedTransactionFile.txt");

  filepath="dailyTransactionFile" + counter + ".txt";
  inpf=new File(filepath);

  while(inpf.exists() && !inpf.isDirectory()) {

      //Initialize Buffered reader with the next file and output to merged
      br=new BufferedReader(new FileReader(filepath));
      
      String line = br.readLine();
      while(line != null){
        fr.write(line+"\r\n");
        line = br.readLine();
      }
    counter=counter+1;
    filepath="dailyTransactionFile" + counter + ".txt";
    inpf=new File(filepath);
  }
  //close readers and writers
  br.close();
  fr.close();
  }

}