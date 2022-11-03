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

import com.izacueio.tadsvscode.models.dto.GenreDTO;
import com.izacueio.tadsvscode.models.entity.Genre;
import com.izacueio.tadsvscode.models.repository.GenreRepository;

@RestController
@RequestMapping("/genres")
public class GenreController{

    @Autowired
    GenreRepository GenreRepository;

    @GetMapping
    public ResponseEntity<Object> getAllGenres(){
        return ResponseEntity.status(HttpStatus.OK).body(GenreRepository.findAll());
    }

    @PostMapping // {nome: 'genero do livro'}
    public ResponseEntity<Object> saveGenres(@RequestBody GenreDTO genreDTO){
        // requeste body é o que define que ele ira retornar no get dentro do body uma string ou seja um objeto java
        
        Genre genreEntity = new Genre();
        BeanUtils.copyProperties(genreDTO, genreEntity); 
        //mandando os dados pro banco

        return ResponseEntity.status(HttpStatus.OK).body(GenreRepository.save(genreEntity));
        //o genreRepository é pra retornar uma instancia do entity que vai direto p banco

    }
    @PutMapping("/{id}") // {nome: 'nome novo do livro' e o ID do livro}
     public ResponseEntity<Object> updateGenre(@PathVariable Integer id, @RequestBody GenreDTO genreDTO)
     {

        //procurar o ID que possui o genero que deseja alterar ou atualizar

        /* opção 1 sem usar o optional<>
        Genre genreEntity = GenreRepository.findById(id).get(); */

        //opção 2 usando o optional para fazer a verificação se o ID existe no banco.

        Optional<Genre> genreExists = GenreRepository.findById(id);

        if(!genreExists.isPresent()){
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Genre not found!");
        }

        Genre genreEntity = genreExists.get(); //aqui se o ID solicitado existir. Ele seleciona.
        BeanUtils.copyProperties(genreDTO, genreEntity); // aqui ele copia o genreDTO digitado pelo usuario, novo genero no caso e joga no banco no lugar do anterior, ou seja ele atualiza.

        return ResponseEntity.status(HttpStatus.OK).body(GenreRepository.save(genreEntity));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Object> deleteGenre(@PathVariable Integer id){
        Optional<Genre> genreEntity = GenreRepository.findById(id);

        if(!genreEntity.isPresent()){
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Genre not found!");
        }

        GenreRepository.deleteById(id);

        return ResponseEntity.status(HttpStatus.OK).body("genre has be deleted.");

    }


}