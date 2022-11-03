package com.izacueio.tadsvscode.Controllers;
//Resource: BOOK(Get, post, delete e PUT)

import java.util.Optional;

import org.springframework.beans.BeanUtils;
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

import com.izacueio.tadsvscode.models.dto.AuthorDTO;
import com.izacueio.tadsvscode.models.entity.Author;
import com.izacueio.tadsvscode.models.repository.AuthorRepository;

@RestController
@RequestMapping("/authors")
public class AuthorController{

    @Autowired
    AuthorRepository AuthorRepository;

    @GetMapping
    public ResponseEntity<Object> getAllAuthors(){
        return ResponseEntity.status(HttpStatus.OK).body(AuthorRepository.findAll());
    }

    @PostMapping // {nome: 'autores de livros'}
    public ResponseEntity<Object> saveAuthors(@RequestBody AuthorDTO AuthorDTO){
        // requeste body é o que define que ele ira retornar no get dentro do body uma string ou seja um objeto java
        
        Author AuthorEntity = new Author();
        BeanUtils.copyProperties(AuthorDTO, AuthorEntity); 
        //mandando os dados pro banco

        return ResponseEntity.status(HttpStatus.OK).body(AuthorRepository.save(AuthorEntity));
        //o AuthorRepository é pra retornar uma instancia do entity que vai direto p banco

    }
    @PutMapping("/{id}") // {nome: 'nome novo do livro' e o ID do livro}
     public ResponseEntity<Object> updateAuthor(@PathVariable Integer id, @RequestBody AuthorDTO AuthorDTO)
     {

        //procurar o ID que possui o genero que deseja alterar ou atualizar

        /* opção 1 sem usar o optional<>
        Author AuthorEntity = AuthorRepository.findById(id).get(); */

        //opção 2 usando o optional para fazer a verificação se o ID existe no banco.

        Optional<Author> AuthorExists = AuthorRepository.findById(id);

        if(!AuthorExists.isPresent()){
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Author not found!");
        }

        Author AuthorEntity = AuthorExists.get(); //aqui se o ID solicitado existir. Ele seleciona.
        BeanUtils.copyProperties(AuthorDTO, AuthorEntity); // aqui ele copia o AuthorDTO digitado pelo usuario, novo genero no caso e joga no banco no lugar do anterior, ou seja ele atualiza.

        return ResponseEntity.status(HttpStatus.OK).body(AuthorRepository.save(AuthorEntity));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Object> deleteAuthor(@PathVariable Integer id){
        Optional<Author> AuthorEntity = AuthorRepository.findById(id);

        if(!AuthorEntity.isPresent()){
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Author not found!");
        }

        AuthorRepository.deleteById(id);

        return ResponseEntity.status(HttpStatus.OK).body("Author has be deleted.");

    }


}