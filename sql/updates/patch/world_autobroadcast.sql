/*
Navicat MySQL Data Transfer
Source Server         : mangos
Source Server Version : 50535
Source Host           : localhost:3306
Source Database       : mangos
Target Server Type    : MYSQL
Target Server Version : 50535
File Encoding         : 65001
Date: 2015-05-05 14:18:08
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for autobroadcast
-- ----------------------------
DROP TABLE IF EXISTS `autobroadcast`;
CREATE TABLE `autobroadcast` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `text` longtext NOT NULL,
  `next` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of autobroadcast
-- ----------------------------