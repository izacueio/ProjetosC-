package com.izacueio.tadsvscode.Controllers;
//Resource: BOOK(Get, post, delete e PUT)

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/books") // o que vai dps do localhost:8080 para acessar a API
public class BookController {
    
    @GetMapping
    public ResponseEntity<Object> getAllBooks(){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o GET");

    }

    @PostMapping // {nome: 'nome do livro'}
    public ResponseEntity<Object> saveBooks(){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o POST");

    }
    @PutMapping("/{id}") // {nome: 'nome novo do livro' e o ID do livro}
     public ResponseEntity<Object> updateBooks(@PathVariable Integer id){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o PUT" + id);

    }
    @DeleteMapping
    public ResponseEntity<Object> deleteBooks(){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o Delete");

    }
}