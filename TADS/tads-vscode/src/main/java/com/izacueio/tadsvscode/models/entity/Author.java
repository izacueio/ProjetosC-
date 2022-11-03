package com.izacueio.tadsvscode.models.entity;

import javax.persistence.*;

import lombok.AllArgsConstructor;
import lombok.Getter; //cria os getters na hora da compilação, integer, strings
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor //metodos incorporados automaticamente
@NoArgsConstructor
@Entity
@Table (name = "authors")
    
    public class Author {
    @Id //é do javax para gerar o id
    @GeneratedValue(strategy = GenerationType.AUTO) //Gerar o id automatico
    private Integer id;
    private String name;

    }
