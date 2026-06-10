#include "../../headers/repo/GymRepositoryMemory.h"
#include "../../headers/model/Modality.h"

Gym* GymRepositoryMemory::model = nullptr;

Gym* GymRepositoryMemory::getModel() {

    if (model == nullptr)
    {
        model = new Gym("ISEP Gym", "Porto");

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

        model->getInstructorContainer().add(
            Instructor(
                "Joao Silva",
                "INS001",
                "joao@gym.pt",
                "0001",
                "Boxe"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Ana Costa",
                "INS002",
                "ana@gym.pt",
                "0002",
                "Muay Thai"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Pedro Santos",
                "INS003",
                "pedro@gym.pt",
                "0003",
                "Jiu-Jitsu"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Ricardo Lopes",
                "INS004",
                "ricardo@gym.pt",
                "0004",
                "Karate"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Tiago Fernandes",
                "INS005",
                "tiago@gym.pt",
                "0005",
                "Kickboxing"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Andre Ribeiro",
                "INS006",
                "andre@gym.pt",
                "0006",
                "MMA"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Bruno Rocha",
                "INS007",
                "bruno@gym.pt",
                "0007",
                "Musculacao"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Marta Ferreira",
                "INS008",
                "marta@gym.pt",
                "0008",
                "CrossFit"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Sofia Almeida",
                "INS009",
                "sofia@gym.pt",
                "0009",
                "Cycling"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Carla Martins",
                "INS010",
                "carla@gym.pt",
                "0010",
                "Yoga"
            )
        );

        model->getInstructorContainer().add(
            Instructor(
                "Miguel Sousa",
                "INS011",
                "miguel@gym.pt",
                "0011",
                "Pilates"
            )
        );

        model->getRoomContainer().addRoom(
            new Room("Sala A", 5)
        );

        model->getRoomContainer().addRoom(
            new Room("Sala B", 10)
        );

        model->getRoomContainer().addRoom(
            new Room("Sala C", 20)
        );
    }

    return model;
}