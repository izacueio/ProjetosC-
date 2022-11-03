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
@Table (name = "genres")
public class Genre{

@Id //é do javax para gerar o id
@GeneratedValue(strategy = GenerationType.AUTO) //Gerar o id automatico
private Integer id;
private String name;

@JsonBackReference
@ManyToMany
@JoinTable(name = "books_genres", joinColumns = @JoinColumn(name = "genre_id" ), inverseJoinColumns = @JoinColumn(name = "book_id"))
private List<Book> books; //relacionamento muitos pra muitos correto 


}