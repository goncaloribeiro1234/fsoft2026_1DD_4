#include "../../headers/repo/GymRepositoryMemory.h"
#include "../../headers/model/Modality.h"

Gym* GymRepositoryMemory::model = nullptr;

Gym* GymRepositoryMemory::getModel() {

    if (model == nullptr) {

        model = new Gym("ISEP Gym", "Porto");

        // ARTES MARCIAIS E COMBATE

        model->getModalityContainer().add(
                Modality(
                        "Boxe",
                        "Desporto de combate"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Muay Thai",
                        "Arte marcial tailandesa"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Jiu-Jitsu",
                        "Arte marcial de submissao"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Karate",
                        "Arte marcial japonesa"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Kickboxing",
                        "Combate com socos e pontapes"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "MMA",
                        "Mixed Martial Arts"
                )
        );

        // FITNESS

        model->getModalityContainer().add(
                Modality(
                        "Musculacao",
                        "Treino de forca"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "CrossFit",
                        "Treino funcional de alta intensidade"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Cycling",
                        "Aulas de bicicleta indoor"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Yoga",
                        "Flexibilidade e bem-estar"
                )
        );

        model->getModalityContainer().add(
                Modality(
                        "Pilates",
                        "Postura e fortalecimento muscular"
                )
        );
    }
        model->getInstructorContainer().add(
    Instructor(
        "Joao Silva",
        "INS001",
        "joao@gym.pt",
        "1111",
        "Boxe"
    )
);

        model->getInstructorContainer().add(
            Instructor(
                "Ana Costa",
                "INS002",
                "ana@gym.pt",
                "2222",
                "Muay Thai"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Pedro Santos",
                "INS003",
                "pedro@gym.pt",
                "3333",
                "Jiu-Jitsu"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Ricardo Lopes",
                "INS004",
                "ricardo@gym.pt",
                "4444",
                "Karate"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Bruno Rocha",
                "INS005",
                "bruno@gym.pt",
                "5555",
                "Musculacao"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Marta Ferreira",
                "INS006",
                "marta@gym.pt",
                "6666",
                "CrossFit"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Sofia Almeida",
                "INS007",
                "sofia@gym.pt",
                "7777",
                "Cycling"
            )
        );

    return model;
}