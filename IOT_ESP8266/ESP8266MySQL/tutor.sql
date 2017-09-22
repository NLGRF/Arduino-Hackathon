-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Nov 15, 2016 at 05:07 PM
-- Server version: 10.1.16-MariaDB
-- PHP Version: 5.6.24

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `tutor`
--

-- --------------------------------------------------------

--
-- Table structure for table `esp8266`
--

CREATE TABLE `esp8266` (
  `id` int(11) NOT NULL,
  `temp` int(11) NOT NULL,
  `day` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `esp8266`
--

--
-- Indexes for dumped tables
--

--
-- Indexes for table `esp8266`
--
ALTER TABLE `esp8266`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `esp8266`
--
ALTER TABLE `esp8266`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;