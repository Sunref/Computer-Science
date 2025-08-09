package olamundoweb.servlets;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 *
 * @author fernanda
 */
@WebServlet( name = "OlaServlet", urlPatterns = { "/ola" })
public class OlaServlet extends HttpServlet{
    
    protected void posRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("Olá Mundo!");  
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        posRequest(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        posRequest(req, resp);
    }
    
    
    
}
