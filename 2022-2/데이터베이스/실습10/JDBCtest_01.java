import java.sql.*;
public class JDBCtest_01 {

	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			System.out.println("OK!");
		}
		catch(ClassNotFoundException ee) {
			System.err.println("Error!");
		}
		
		Connection conn = null;
		String url = "jdbc:mysql://localhost/academicDB?serverTimezone=UTC";
		
		String id = "root";
		String pass = "kom142536*";
		Statement stmt = null;
		ResultSet rs = null;
		String query = "select * from student";
		
		try {
			conn = DriverManager.getConnection(url, id, pass);
			//실습11_3
			//stmt = conn.createStatement();
			stmt = conn.prepareCall("call studentProc()");
			//rs = stmt.executeQuery(query);
			rs = stmt.executeQuery(query);
			while(rs.next()) {
				System.out.println(rs.getInt(1) + ", " + rs.getString(2) + ", "
						+ rs.getString(3) + ", " + rs.getString(4));
			}
			rs.close();
			stmt.close();
			conn.close();
		}
		catch(SQLException ee) {
			System.out.println("error = " + ee.toString());
		}
	}

}
