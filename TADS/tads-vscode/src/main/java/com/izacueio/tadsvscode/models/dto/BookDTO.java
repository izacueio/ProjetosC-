package com.izacueio.tadsvscode.models.dto;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@ToString
@Setter
@Getter
@NoArgsConstructor
@AllArgsConstructor


public class BookDTO {

    private String tittle;
    private String description;
    private Integer authorId;

    private List<Integer> genres;

    
}
