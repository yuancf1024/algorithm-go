import java.util.Scanner;

public class Main {
	public boolean isNumber(String str) {

        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

	 public static void main(String[] args) {
				 
		 Main t1 = new Main();
		 
		 Scanner input = new Scanner(System.in);
		 
		 //输入
		 //System.out.println("请输入电费账户：");
		 String n = input.next();
		 
		 if(n.length() == 8) 
		 {
			 //获取字符串的第一位字母
			 char n1 = n.charAt(0);
			 String n2 = String.valueOf(n.charAt(1));//转字符串
			 String n3 = String.valueOf(n.charAt(2));
			 if( n1 == 's' || n1 == 'd' ) {
				 
				 if(t1.isNumber(n2)&& t1.isNumber(n3)) {
					 int flag1 = Integer.parseInt(n2)*10 +Integer.parseInt(n3) ;
					 
					 if(flag1 <= 30 && flag1 >= 1 ) {
						 String n4 = String.valueOf(n.charAt(3));//转字符串
						 String n5 = String.valueOf(n.charAt(4));
						 
						 if(t1.isNumber(n4)&& t1.isNumber(n5)) {
							 int flag2 = Integer.parseInt(n4)*10 +Integer.parseInt(n5) ;

							 if(flag1 <= 12) {
								 if(flag2 <= 3 && flag2 >= 1 ) {
									 String n6 = String.valueOf(n.charAt(5));//转字符串
									 String n7 = String.valueOf(n.charAt(6));
									 if(t1.isNumber(n6)&& t1.isNumber(n7)) {
										 int flag3 = Integer.parseInt(n6)*10 +Integer.parseInt(n7) ;
										 if(flag3 <= 6 && flag3 >= 1)
										 {
											 
											 
											 String n8 = String.valueOf(n.charAt(7));
											 if(t1.isNumber(n8)) {
												 int flag4 = Integer.parseInt(n8) ;
												 if(flag4 <= 3 && flag4 >= 1) {
													 System.out.println("账号输入正确");

													 
												 }
												 else {
													 System.out.println("Error：账号输入错误");

												 }
											 }
											 else {
												 System.out.println("Error：账号输入错误");

											 }

										 }
										 else {
											 System.out.println("Error：账号输入错误");

										 }
									 }
									 
								 }
								 else {
									 System.out.println("Error：账号输入错误");

								 }
							 }
							 else if(flag1 >= 13) {
								 if(flag2 <= 5 && flag2 >= 1 ) {
									 String n6 = String.valueOf(n.charAt(5));//转字符串
									 String n7 = String.valueOf(n.charAt(6));
									 if(t1.isNumber(n6)&& t1.isNumber(n7)) {
										 int flag3 = Integer.parseInt(n6)*10 +Integer.parseInt(n7) ;
										 if(flag3 <= 30 && flag3 >= 1)
										 {
											 String n8 = String.valueOf(n.charAt(7));
											 if(t1.isNumber(n8)) {
												 int flag4 = Integer.parseInt(n8) ;
												 if(flag4 <= 3 && flag4 >= 1) {
													 System.out.println("账号输入正确");

													 
												 }
												 else {
													 System.out.println("Error：账号输入错误");

												 }
											 }
											 else {
												 System.out.println("Error：账号输入错误");

											 }

										 }
										 else {
											 System.out.println("Error：账号输入错误");

										 }
									 }
								 }
								 else {
									 System.out.println("Error：账号输入错误");

								 }
							 }
							 
						 }
						 else {
							 System.out.println("Error：账号输入错误");

						 }

					 }
					 else {
						 System.out.println("Error：账号输入错误");
					 } 
				 }
				 else {
					 System.out.println("Error：账号输入错误");

				 }


			 }
			 else {
				 System.out.println("Error：账号输入错误");

			 }
				 
			 
		 }
		 else {
			 System.out.println("Error：账号输入错误");

		 }
			 
		 
		 
	 }
}