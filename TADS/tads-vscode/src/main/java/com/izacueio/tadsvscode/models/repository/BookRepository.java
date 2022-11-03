package com.izacueio.tadsvscode.models.repository;

import org.springframework.data.repository.CrudRepository;

import com.izacueio.tadsvscode.models.entity.Book;

//verificar se existe as tuplas, transforma  em objetos
public interface BookRepository extends CrudRepository<Book, Integer> {



}