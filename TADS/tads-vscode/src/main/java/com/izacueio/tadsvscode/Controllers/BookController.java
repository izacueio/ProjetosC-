package com.izacueio.tadsvscode.Controllers;
//Resource: BOOK(Get, post, delete e PUT)

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.izacueio.tadsvscode.models.dto.BookDTO;
import com.izacueio.tadsvscode.models.entity.Book;
import com.izacueio.tadsvscode.models.repository.AuthorRepository;
import com.izacueio.tadsvscode.models.repository.BookRepository;
import com.izacueio.tadsvscode.models.repository.GenreRepository;


@RestController
@RequestMapping("/books") // o que vai dps do localhost:8080 para acessar a API
public class BookController {
    
    @Autowired
    BookRepository bookRepository; //ele via criar os cruds pq ja conhece do framework e via instanciar os objetos automaticamente

    @Autowired
    GenreRepository genreRepository;

    @Autowired
    AuthorRepository authorRepository;

    @GetMapping
    public ResponseEntity<Object> getAllBooks(){
        return ResponseEntity.status(HttpStatus.OK).body(bookRepository.findAll());

    }

    @PostMapping // {nome: 'nome do livro'}
    public ResponseEntity<Object> saveBooks(@RequestBody BookDTO BookDTO){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o POST" + BookDTO);

    }
    @PutMapping("/{id}") // {nome: 'nome novo do livro' e o ID do livro}
     public ResponseEntity<Object> updateBooks(@PathVariable Integer id){
        return ResponseEntity.status(HttpStatus.OK).body("invocou o PUT" + id);

    }
    @DeleteMapping("/{id}")
    public ResponseEntity<Object> deleteBook(@PathVariable Integer id){
        Optional<Book> bookEntity = bookRepository.findById(id);

        if(!bookEntity.isPresent()){
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("book not found");
        }

        bookRepository.deleteById(id);

        return ResponseEntity.status(HttpStatus.OK).body("book has been removed.");

    }


}