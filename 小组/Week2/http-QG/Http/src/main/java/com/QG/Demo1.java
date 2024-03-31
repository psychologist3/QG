package com.QG;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Map;

@WebServlet("/http1" )
public class Demo1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        extracted(req);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {


        extracted(req);
        resp.setStatus(302);
        resp.setHeader("location","http://localhost:8080/Http/http2");

    }

    private static void extracted(HttpServletRequest req) {
        String method = req.getMethod();
        if("GET".equals(method)){
            System.out.println("get...");

        } else if ("POST".equals(method)) {
            System.out.println("post...");

        }

        Map<String, String[]> parameterMap = req.getParameterMap();
        for(String key: parameterMap.keySet()){
            System.out.print(key+":");

            String[] values = parameterMap.get(key);
            for(String value : values){
                System.out.print(value+":");
            }

            System.out.println();
        }
    }
}
