CREATE DATABASE order_management; USE order_management;
-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 05, 2019 at 08:26 AM
-- Server version: 10.1.21-MariaDB
-- PHP Version: 7.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `order_management`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `Tables` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`Tables`) VALUES
('10');

-- --------------------------------------------------------

--
-- Table structure for table `food_menu`
--

CREATE TABLE `food_menu` (
  `itemid` int(11) NOT NULL,
  `catid` varchar(255) NOT NULL,
  `desc` varchar(255) NOT NULL,
  `pieces` int(255) NOT NULL,
  `price` float(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

--
-- Dumping data for table `food_menu`
--

INSERT INTO `food_menu` (`itemid`, `catid`, `desc`, `pieces`, `price`) VALUES
(1, 'Burgers', 'Snacker', 20, 190.00),
(2, 'Burgers', 'Zinger Burger', 15, 520.00),
(3, 'Burgers', 'KFC Griller', 25, 490.00),
(4, 'Burgers', 'Veggie Burger', 20, 390.00),
(5, 'Burgers', 'Classic Sub', 30, 290.00),
(6, 'Burgers', 'Twister', 40, 520.00),
(7, 'Snacks', 'Hot and Crispy Chicken - 2 PCs', 20, 530.00),
(8, 'Snacks', 'Hot and Crispy Chicken - 4 PCs', 20, 980.00),
(16, 'Snacks', 'Hot and Crispy Fillet', 20, 490.00),
(17, 'Snacks', 'Hot Drumlets - 6 PCs', 20, 430.00),
(18, 'Snacks', 'Hot Drumlets - 20 PCs', 20, 1330.00),
(19, 'Snacks', 'KFC Colonels Fries', 20, 230.00),
(20, 'Snacks', 'Crispy Strips', 20, 370.00),
(21, 'Snacks', 'Hot Crispy Bites - 9 PCs', 20, 440.00),
(22, 'Snacks', 'Hot Crispy Bites - 20 PCs', 20, 890.00),
(23, 'Buckets', 'Hot and Crispy Chicken - 8 PCs', 10, 1840.00),
(24, 'Buckets', 'Hot and Crispy Chicken - 12 PCs', 15, 2640.00),
(25, 'Buckets', 'BBQ Chicken - 6 PCs', 20, 1840.00),
(27, 'Buriyani', 'Chicken Buriyani', 10, 230.00),
(28, 'Buriyani', 'Fiery Grilled Chicken Buriyani', 15, 380.00),
(29, 'Buriyani', 'KFC Chicken Spice Rice', 20, 390.00),
(30, 'Sawan', 'KFC Chicken Sawan', 10, 1650.00),
(31, 'Smart Combos - Meals', 'Twisted Meal', 10, 710.00),
(32, 'Smart Combos - Meals', 'Veggie Burger Meal', 10, 650.00),
(33, 'Smart Combos - Meals', '2 PCs Chicken Meal', 10, 660.00),
(34, 'Desserts and Beverages', 'Ice Cream Cone - Wafflle Cone', 20, 60.00),
(35, 'Desserts and Beverages', 'Mini Sundae', 20, 140.00),
(36, 'Desserts and Beverages', 'Drinking Yogurt', 20, 70.00),
(37, 'Desserts and Beverages', 'Pepsi or 7up', 20, 160.00),
(38, 'Desserts and Beverages', 'Mango Nectar', 20, 80.00),
(39, 'Family Meals', '4 PCs Chicken Buriyani Meal', 20, 1170.00),
(40, 'Family Meals', '8 PCs Chicken Buriyani Meal', 20, 2230.00),
(41, 'Family Meals', '12 PCs Chicken Buriyani Meal', 20, 3350.00),
(42, 'Add - Ons', 'Onion Sambol', 20, 70.00);

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `orderid` int(11) NOT NULL,
  `tableid` int(11) NOT NULL,
  `food_item` text NOT NULL,
  `pieces` varchar(255) NOT NULL,
  `status` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`orderid`, `tableid`, `food_item`, `pieces`, `status`) VALUES
(736, 5, 'Zinger Burger', '3', 'Start'),
(739, 5, 'Classic Sub', '3', 'Process'),
(740, 3, 'Hot and Crispy Chicken - 2 PCs', '5', 'Start'),
(741, 4, 'Hot Crispy Bites - 9 PCs', '9', 'Delivered'),
(742, 5, 'Fiery Grilled Chicken Buriyani', '4', 'Process');

-- --------------------------------------------------------

--
-- Table structure for table `table plan`
--

CREATE TABLE `table plan` (
  `tableid` int(11) NOT NULL,
  `status` varchar(10) NOT NULL,
  `Delivery` varchar(255) NOT NULL,
  `Payment` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

--
-- Dumping data for table `table plan`
--

INSERT INTO `table plan` (`tableid`, `status`, `Delivery`, `Payment`) VALUES
(1, 'Open', '----------', '----------'),
(2, 'Dirty', '----------', '----------'),
(3, 'Open', '----------', '----------'),
(4, 'Occupied', 'Delivered', 'Not yet'),
(5, 'Occupied', 'Not yet', 'Not yet'),
(6, 'Occupied', 'Delivered', 'Paid'),
(7, 'Open', '----------', '----------'),
(8, 'Open', '----------', '----------'),
(9, 'Dirty', '----------', '----------'),
(10, 'Dirty', '----------', '----------');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created_at` datetime DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `created_at`) VALUES
(3, 'abc', '$2y$10$wOUZ4/g9IZp65M7fJqfHnewR0UmzzxefvK0MjfvzHxONzd.n4tAqy', '2019-09-19 14:40:48');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`Tables`),
  ADD UNIQUE KEY `tableid` (`Tables`),
  ADD UNIQUE KEY `Tables` (`Tables`);

--
-- Indexes for table `food_menu`
--
ALTER TABLE `food_menu`
  ADD PRIMARY KEY (`itemid`),
  ADD UNIQUE KEY `itemid` (`itemid`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`orderid`),
  ADD UNIQUE KEY `orderid` (`orderid`);

--
-- Indexes for table `table plan`
--
ALTER TABLE `table plan`
  ADD UNIQUE KEY `tableid` (`tableid`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `food_menu`
--
ALTER TABLE `food_menu`
  MODIFY `itemid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=43;
--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
  MODIFY `orderid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=743;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
