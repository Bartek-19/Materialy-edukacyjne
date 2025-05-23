-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 24, 2025 at 05:44 PM
-- Wersja serwera: 10.4.32-MariaDB
-- Wersja PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projekt`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `effort_type`
--

CREATE TABLE `effort_type` (
  `id` int(11) NOT NULL,
  `effort_type_name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `effort_type`
--

INSERT INTO `effort_type` (`id`, `effort_type_name`) VALUES
(1, 'Dynamic'),
(2, 'Max'),
(4, 'Speed'),
(3, 'Volume');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `end_survey`
--

CREATE TABLE `end_survey` (
  `id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `users_training_plan_id` int(11) NOT NULL,
  `was_tracking_sleep` binary(1) NOT NULL,
  `amount_of_sleep` int(11) DEFAULT NULL,
  `was_tracking_nutrition` binary(1) NOT NULL,
  `personal_evaluation` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `end_survey`
--

INSERT INTO `end_survey` (`id`, `user_id`, `users_training_plan_id`, `was_tracking_sleep`, `amount_of_sleep`, `was_tracking_nutrition`, `personal_evaluation`) VALUES
(1, 1, 1, 0x31, 8, 0x30, NULL),
(2, 1, 2, 0x30, NULL, 0x30, NULL),
(3, 2, 3, 0x30, NULL, 0x30, NULL);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `excercise`
--

CREATE TABLE `excercise` (
  `id` int(11) NOT NULL,
  `name` varchar(150) NOT NULL,
  `description` varchar(200) DEFAULT NULL,
  `excercise_category_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `excercise`
--

INSERT INTO `excercise` (`id`, `name`, `description`, `excercise_category_id`) VALUES
(1, 'Back Squat', 'Squat performed in a bilateral stance, with a barbell placed in a high-bar or a low-bar position, performed to a competition required depth', 1),
(2, 'Bench Press', 'Pressing in the laying position on a flat bench, performed to a competition standards', 1),
(3, 'Deadlift', 'Performed in a conventional or a sumo stance, ', 1),
(4, 'Front Squat', 'Performed with a barbell placed on shoulders in front of the neck, in a front rack position, performed to a full depth', 1),
(5, 'Overhead press', 'Performed in a standing position strict overhead press', 2),
(6, 'Pull-up', 'Pull-up performed conventionally with a overhand grip, the bar must reach the neck and sternum area at the top of the repetition', 2),
(7, 'Lunges', 'Unilateral squat performed wth one leg in front of the body and the second leg behind the body placed on the ground, feet pointed forward', 1),
(8, 'Triceps pushdown', 'Performed with a cable machine, with the cable attached at the top, performed by pressing the attachment down, with elbows tucked to the side of the body', 3),
(9, 'Back extensions', 'Performed on a roman chair bench by bending and extending in the hips while avoiding movement in the lumbard spine and in the knees', 3);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `excercises_in_training`
--

CREATE TABLE `excercises_in_training` (
  `excercise_id` int(11) NOT NULL,
  `repetitions` int(11) NOT NULL,
  `sets` int(11) NOT NULL,
  `weight` float NOT NULL,
  `training_day_id` int(11) NOT NULL,
  `effort_type_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `excercise_category`
--

CREATE TABLE `excercise_category` (
  `id` int(11) NOT NULL,
  `category_name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `excercise_category`
--

INSERT INTO `excercise_category` (`id`, `category_name`) VALUES
(2, 'Compound'),
(1, 'Global'),
(3, 'Isolated');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `excercise_has_movement_pattern`
--

CREATE TABLE `excercise_has_movement_pattern` (
  `excercise_id` int(11) NOT NULL,
  `movement_pattern_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `excercise_has_movement_pattern`
--

INSERT INTO `excercise_has_movement_pattern` (`excercise_id`, `movement_pattern_id`) VALUES
(1, 2),
(1, 4),
(1, 5),
(1, 10),
(2, 4),
(2, 11),
(3, 2),
(3, 4),
(3, 9),
(4, 2),
(4, 4),
(4, 5),
(4, 10),
(5, 2),
(5, 4),
(5, 5),
(5, 12),
(6, 1),
(6, 7),
(7, 2),
(7, 6),
(7, 9),
(7, 10),
(7, 16),
(8, 2),
(8, 14),
(9, 2),
(9, 4),
(9, 5),
(9, 9);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `excercise_target_muscle_group`
--

CREATE TABLE `excercise_target_muscle_group` (
  `excercise_id` int(11) NOT NULL,
  `target_muscle_group_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `excercise_target_muscle_group`
--

INSERT INTO `excercise_target_muscle_group` (`excercise_id`, `target_muscle_group_id`) VALUES
(1, 7),
(1, 9),
(1, 10),
(1, 11),
(1, 13),
(1, 14),
(1, 15),
(1, 16),
(2, 2),
(2, 3),
(2, 4),
(2, 5),
(2, 7),
(2, 8),
(2, 9),
(2, 10),
(3, 5),
(3, 6),
(3, 7),
(3, 8),
(3, 9),
(3, 10),
(3, 11),
(3, 13),
(3, 14),
(3, 15),
(3, 16),
(4, 3),
(4, 5),
(4, 7),
(4, 9),
(4, 10),
(4, 11),
(4, 13),
(4, 14),
(4, 15),
(4, 16),
(5, 2),
(5, 3),
(5, 5),
(5, 6),
(5, 7),
(5, 9),
(5, 10),
(5, 13),
(6, 1),
(6, 3),
(6, 5),
(6, 7),
(6, 8),
(6, 13),
(7, 7),
(7, 9),
(7, 10),
(7, 11),
(7, 13),
(7, 14),
(7, 15),
(7, 16),
(8, 2),
(8, 8),
(9, 9),
(9, 10),
(9, 13),
(9, 14);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `executed_sets`
--

CREATE TABLE `executed_sets` (
  `id` int(11) NOT NULL,
  `excercise_id` int(11) NOT NULL,
  `executed_repetitions` int(11) NOT NULL,
  `weight_used` float NOT NULL,
  `training_day_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `movement_pattern`
--

CREATE TABLE `movement_pattern` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `movement_pattern`
--

INSERT INTO `movement_pattern` (`id`, `name`) VALUES
(5, 'Anti-Extension'),
(4, 'Anti-Flexion'),
(6, 'Anti-Rotation'),
(14, 'Decline Push'),
(2, 'Extension'),
(1, 'Flexion'),
(9, 'Hip Hinge'),
(8, 'Horizontal Pull'),
(11, 'Horizontal Push'),
(13, 'Incline Push'),
(16, 'Lunge'),
(15, 'Raise'),
(3, 'Rotation'),
(10, 'Squat'),
(7, 'Vertical Pull'),
(12, 'Vertical Push');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `target_muscle_group`
--

CREATE TABLE `target_muscle_group` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `target_muscle_group`
--

INSERT INTO `target_muscle_group` (`id`, `name`) VALUES
(1, 'Biceps'),
(2, 'Triceps'),
(3, 'Shoulders'),
(4, 'Pectorals'),
(5, 'Forearms'),
(6, 'Neck'),
(7, 'Upper back'),
(8, 'Lats'),
(9, 'Lower back'),
(10, 'Glutes'),
(11, 'Adductors'),
(12, 'Hip flexors'),
(13, 'Abdominals'),
(14, 'Hamstrings'),
(15, 'Quadriceps'),
(16, 'Calves');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `training_day`
--

CREATE TABLE `training_day` (
  `id` int(11) NOT NULL,
  `training_plan_id` int(11) NOT NULL,
  `week_day` varchar(45) NOT NULL,
  `week` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `training_method`
--

CREATE TABLE `training_method` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `duration_of_cycle` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `training_method`
--

INSERT INTO `training_method` (`id`, `name`, `duration_of_cycle`) VALUES
(1, '5x5', 4),
(2, '5x30', 1),
(3, 'Texas Method', 3),
(4, 'Condense Conjugate', 4);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `training_plan`
--

CREATE TABLE `training_plan` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `training_method_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `training_plan`
--

INSERT INTO `training_plan` (`id`, `name`, `training_method_id`) VALUES
(1, 'User1-5x5-1', 1),
(2, 'User1-TexMet-1', 3),
(3, 'User2-5x5-1', 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `username` varchar(45) NOT NULL,
  `password` varchar(45) NOT NULL,
  `email` varchar(45) NOT NULL,
  `active_status` tinyint(1) NOT NULL,
  `create_date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `username`, `password`, `email`, `active_status`, `create_date`) VALUES
(1, 'user1', 'pass1', 'user1@email.com', 1, '2025-03-01 16:50:01'),
(2, 'user2', 'pass2', 'user2@email.com', 1, '2025-03-24 16:50:02');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `users_training_plans`
--

CREATE TABLE `users_training_plans` (
  `user_id` int(11) NOT NULL,
  `plan_id` int(11) NOT NULL,
  `begin_date` date NOT NULL,
  `end_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `users_training_plans`
--

INSERT INTO `users_training_plans` (`user_id`, `plan_id`, `begin_date`, `end_date`) VALUES
(1, 1, '2025-03-03', '2025-03-16'),
(1, 2, '2025-03-31', '2025-04-20'),
(2, 3, '2025-03-31', '2025-04-06');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `user_records`
--

CREATE TABLE `user_records` (
  `user_id` int(11) NOT NULL,
  `max_squat` float DEFAULT NULL,
  `max_bench` float DEFAULT NULL,
  `max_deadlift` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `user_stats`
--

CREATE TABLE `user_stats` (
  `user_id` int(11) NOT NULL,
  `plans_completed` int(11) NOT NULL,
  `trainings_completed` int(11) NOT NULL,
  `sets_completed` int(11) NOT NULL,
  `total_tonnage` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `effort_type`
--
ALTER TABLE `effort_type`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `effort_type_name_UNIQUE` (`effort_type_name`);

--
-- Indeksy dla tabeli `end_survey`
--
ALTER TABLE `end_survey`
  ADD PRIMARY KEY (`id`,`user_id`,`users_training_plan_id`),
  ADD KEY `fk_end_survey_users_training_plans1_idx` (`user_id`,`users_training_plan_id`);

--
-- Indeksy dla tabeli `excercise`
--
ALTER TABLE `excercise`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_excercise_excercise_category1_idx` (`excercise_category_id`);

--
-- Indeksy dla tabeli `excercises_in_training`
--
ALTER TABLE `excercises_in_training`
  ADD PRIMARY KEY (`excercise_id`,`training_day_id`,`effort_type_id`) USING BTREE,
  ADD KEY `fk_excercise_has_training_plan_excercise_idx` (`excercise_id`),
  ADD KEY `fk_excercise_in_training_plan_trainings1_idx` (`training_day_id`),
  ADD KEY `fk_excercises_in_training_effort_type1_idx` (`effort_type_id`);

--
-- Indeksy dla tabeli `excercise_category`
--
ALTER TABLE `excercise_category`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `categroy_name_UNIQUE` (`category_name`);

--
-- Indeksy dla tabeli `excercise_has_movement_pattern`
--
ALTER TABLE `excercise_has_movement_pattern`
  ADD PRIMARY KEY (`excercise_id`,`movement_pattern_id`),
  ADD KEY `fk_excercise_has_movement_pattern_movement_pattern1_idx` (`movement_pattern_id`),
  ADD KEY `fk_excercise_has_movement_pattern_excercise1_idx` (`excercise_id`);

--
-- Indeksy dla tabeli `excercise_target_muscle_group`
--
ALTER TABLE `excercise_target_muscle_group`
  ADD PRIMARY KEY (`excercise_id`,`target_muscle_group_id`),
  ADD KEY `fk_excercise_has_excercise_target_muscle_group_excercise_ta_idx` (`target_muscle_group_id`),
  ADD KEY `fk_excercise_has_excercise_target_muscle_group_excercise1_idx` (`excercise_id`);

--
-- Indeksy dla tabeli `executed_sets`
--
ALTER TABLE `executed_sets`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_executed_sets_excercise1` (`excercise_id`),
  ADD KEY `fk_executed_sets_training_day1` (`training_day_id`);

--
-- Indeksy dla tabeli `movement_pattern`
--
ALTER TABLE `movement_pattern`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name_UNIQUE` (`name`);

--
-- Indeksy dla tabeli `target_muscle_group`
--
ALTER TABLE `target_muscle_group`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `training_day`
--
ALTER TABLE `training_day`
  ADD PRIMARY KEY (`id`,`training_plan_id`),
  ADD KEY `fk_trainings_training_plan1` (`training_plan_id`);

--
-- Indeksy dla tabeli `training_method`
--
ALTER TABLE `training_method`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `method_id_UNIQUE` (`id`),
  ADD UNIQUE KEY `name_UNIQUE` (`name`);

--
-- Indeksy dla tabeli `training_plan`
--
ALTER TABLE `training_plan`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_training_plan_training_method1_idx` (`training_method_id`);

--
-- Indeksy dla tabeli `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `user_id_UNIQUE` (`id`),
  ADD UNIQUE KEY `username_UNIQUE` (`username`),
  ADD UNIQUE KEY `email_UNIQUE` (`email`);

--
-- Indeksy dla tabeli `users_training_plans`
--
ALTER TABLE `users_training_plans`
  ADD PRIMARY KEY (`user_id`,`plan_id`),
  ADD KEY `fk_user_has_training_plan_training_plan1_idx` (`plan_id`),
  ADD KEY `fk_user_has_training_plan_user1_idx` (`user_id`);

--
-- Indeksy dla tabeli `user_records`
--
ALTER TABLE `user_records`
  ADD PRIMARY KEY (`user_id`),
  ADD KEY `fk_user_stats_user1_idx` (`user_id`);

--
-- Indeksy dla tabeli `user_stats`
--
ALTER TABLE `user_stats`
  ADD PRIMARY KEY (`user_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `end_survey`
--
ALTER TABLE `end_survey`
  ADD CONSTRAINT `fk_end_survey_users_training_plans1` FOREIGN KEY (`user_id`,`users_training_plan_id`) REFERENCES `users_training_plans` (`user_id`, `plan_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `excercise`
--
ALTER TABLE `excercise`
  ADD CONSTRAINT `fk_excercise_excercise_category1` FOREIGN KEY (`excercise_category_id`) REFERENCES `excercise_category` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `excercises_in_training`
--
ALTER TABLE `excercises_in_training`
  ADD CONSTRAINT `fk_excercise_has_training_plan_excercise` FOREIGN KEY (`excercise_id`) REFERENCES `excercise` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_excercise_in_training_training_day1` FOREIGN KEY (`training_day_id`) REFERENCES `training_day` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_excercises_in_training_effort_type1` FOREIGN KEY (`effort_type_id`) REFERENCES `effort_type` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `excercise_has_movement_pattern`
--
ALTER TABLE `excercise_has_movement_pattern`
  ADD CONSTRAINT `fk_excercise_has_movement_pattern_excercise1` FOREIGN KEY (`excercise_id`) REFERENCES `excercise` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_excercise_has_movement_pattern_movement_pattern1` FOREIGN KEY (`movement_pattern_id`) REFERENCES `movement_pattern` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `excercise_target_muscle_group`
--
ALTER TABLE `excercise_target_muscle_group`
  ADD CONSTRAINT `fk_excercise_has_excercise_target_muscle_group_excercise1` FOREIGN KEY (`excercise_id`) REFERENCES `excercise` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_excercise_has_excercise_target_muscle_group_excercise_targ1` FOREIGN KEY (`target_muscle_group_id`) REFERENCES `target_muscle_group` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `executed_sets`
--
ALTER TABLE `executed_sets`
  ADD CONSTRAINT `fk_executed_sets_excercise1` FOREIGN KEY (`excercise_id`) REFERENCES `excercise` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_executed_sets_training_day1` FOREIGN KEY (`training_day_id`) REFERENCES `training_day` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `training_day`
--
ALTER TABLE `training_day`
  ADD CONSTRAINT `fk_trainings_training_plan1` FOREIGN KEY (`training_plan_id`) REFERENCES `training_plan` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `training_plan`
--
ALTER TABLE `training_plan`
  ADD CONSTRAINT `fk_training_plan_training_method1` FOREIGN KEY (`training_method_id`) REFERENCES `training_method` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `users_training_plans`
--
ALTER TABLE `users_training_plans`
  ADD CONSTRAINT `fk_user_has_training_plan_training_plan1` FOREIGN KEY (`plan_id`) REFERENCES `training_plan` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_user_has_training_plan_user1` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `user_records`
--
ALTER TABLE `user_records`
  ADD CONSTRAINT `fk_user_stats_user1` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `user_stats`
--
ALTER TABLE `user_stats`
  ADD CONSTRAINT `fk_user_stats_user2` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
