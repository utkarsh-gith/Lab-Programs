import java.util.*;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class VoterSrv extends HttpServlet{
	public void service(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException{
		res.setContentType("text/html");
		PrintWriter pw = res.getWriter();
		String name = req.getParameter("name");
		int age = Integer.parseInt(req.getParameter("age"));
		pw.println(age >= 18
				? "Hello " + name + "! Welcome to site"
				: "Hello " + name + "! Not Welcome to site");
		pw.println("<br><br><a href = 'index.html'>Back</a>");
		pw.close();
	}
}
