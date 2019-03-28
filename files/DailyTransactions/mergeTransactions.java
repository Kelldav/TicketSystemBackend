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
  filepath="dailyTransactionFile" + counter + ".txt";


  inpf=new File(filepath);
  //Reader and Writers
  BufferedReader br;
  BufferedWriter bw;
  FileWriter fr;
  //If existance is still false
  while(existance==0){
    //File path of the next transaction
    filepath="dailyTransactionFile" + counter + ".txt";
    //Initialize input file
    inpf=new File(filepath);
    if(inpf.exists() && !inpf.isDirectory()) {
        //Initialize Buffered reader with the next file and output to merged
        br=new BufferedReader(new FileReader(filepath));
        outf=new File("mergedTransactionFile.txt");
        //FileWriter and Buffered Writer used to append to the file rather than overwrite
        fr=new FileWriter(outf,true);
        bw=new BufferedWriter(fr);
        //Iterate till readline is empty
        while ((strCurrentLine = br.readLine()) != null) {
            bw.write(strCurrentLine);
        }//End of while for iterating through writer
    }//End of if file exists line
    else{
      existance=1;
    }
    counter=counter+1;
  }//End of existance while loop
  //close readers and writers
  //br.close();
  //bw.close();
  //fr.close();
  }

}//End of class
