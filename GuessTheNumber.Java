import java.util.Scanner;
public class GuessTheNumber{
   public static void main(String[] args){
      int computerNum,
      inputNum=0,
      counter=0;
      
      //asking user to input amount of attempts they want
      while(counter<1 || counter>10){
         System.out.print("Enter the amount of attempts you wish to have: ");
         
         //verifying that a valid input is added
         counter=verifyValue();
         
         if(counter<1 || counter>10)
            System.out.println("Please enter a valid input \n");
      }
      
      //Generating the value for the user to guess
      computerNum= (int)(Math.random()*100)+1;
      
      //giving the user k attempts to guess the number
      while(counter>0){
         counter--;
         
         //keeping the guess inside the parameters
         do{
            
            //asking the user to input their guess 
            System.out.print("Please Enter Your Guess from 1-100: ");
            inputNum=verifyValue();
            if(inputNum>100 || inputNum<1)
               System.out.println("Invalid Input: Please enter a number between 1-100 \n");
         }while(inputNum>100 || inputNum<1);
         
         //verifying if the guess was correct
         System.out.println(CheckNum(computerNum, inputNum));
         
         
         if(CheckNum(computerNum, inputNum).equals("Your guess was correct"))
            break;//breaks out of loop if guess was correct
         
         //informing the user of their attempts remaining
         System.out.println("You have " + counter + " more attempts \n");
         
      }
      //telling the user the number if they used all their attempts
      if(counter == 0)
         System.out.println("You have used up all your attempts the correct number was " + computerNum );
   }
   
   
   public static String CheckNum(int computerNum, int inputNum){
      if(computerNum>inputNum)
         return "Your guess was lower than the number";
      else if(computerNum<inputNum)
         return "Your guess was higher than the number";
      else
         return "Your guess was correct";
   }
   
   public static int verifyValue(){
      Scanner input = new Scanner(System.in);
      if(input.hasNextInt())
            return input.nextInt();
      return 0;
         
   }
}
