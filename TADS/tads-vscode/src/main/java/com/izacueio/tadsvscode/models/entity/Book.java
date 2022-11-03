package com.izacueio.tadsvscode.models.entity;

import java.util.List;

import javax.persistence.*;

import com.fasterxml.jackson.annotation.JsonBackReference;

import lombok.AllArgsConstructor;
import lombok.Getter; //cria os getters na hora da compilação, integer, strings
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor //metodos incorporados automaticamente
@NoArgsConstructor
@Entity
@Table (name = "books")
public class Book{

@Id //é do javax para gerar o id
@GeneratedValue(strategy = GenerationType.AUTO) //Gerar o id automatico
private Integer id;
private String title;
private String description;

@ManyToOne // Relação de muitos para 1, 1 book só tem 1 autor.
@JoinColumn (name = "author_id")
private Author author;

@JsonBackReference
@ManyToMany(mappedBy = "books", fetch = FetchType.LAZY) //vai procurar na classe de generos como deve ser feito, vai olhar no modo fetchtype preguiçoso, só qnd tiver o livro em maos, ele procura a ligação de genero > livro 
private List<Genre> genres;


}