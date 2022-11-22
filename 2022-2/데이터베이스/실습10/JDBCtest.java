
public class JDBCtest {
	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			System.out.println("OK!");
		}
		catch(ClassNotFoundException ee) {
			System.err.println("Error!");
		}
	}
}
