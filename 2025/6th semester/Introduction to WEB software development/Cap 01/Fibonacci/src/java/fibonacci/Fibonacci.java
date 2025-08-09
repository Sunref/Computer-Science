/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fibonacci;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet( name = "Fibonacci", urlPatterns = { "/Calculando" })
public class Fibonacci extends HttpServlet{
    
    public static void fibonacci() {
        long a = 0, b = 1;
        
        System.out.print(a + " " + b + " ");
        
        for (int i = 2; i < 30; i++) {
            long proximo = a + b;
            System.out.print(proximo + " ");
            a = b;
            b = proximo;
        }
        
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        fibonacci();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        fibonacci();
    }
    
    
    
}
