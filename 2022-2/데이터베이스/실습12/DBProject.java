import java.sql.*;

public class DBProject {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String url = "jdbc:mysql://localhost/classicmodels?serverTimezone=UTC";
		String sql = "select firstname, lastname, email from employees";
		String id = "root";
		String pass = "kom142536*";
		
		try(Connection conn = DriverManager.getConnection(url, id, pass);
				Statement stmt = conn.createStatement();
				ResultSet rs = stmt.executeQuery(sql)){
			
			while(rs.next()) {
				System.out.println(rs.getString("firstname") + "\t" + 
									rs.getString("lastname") + "\t" +
									rs.getString("email"));
			}
		}
		catch(SQLException ex) {
			System.out.println(ex.getMessage());
		}
	}

}
