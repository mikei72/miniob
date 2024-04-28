#pragma once

#include <string>
#include <vector>
#include "sql/stmt/stmt.h"
#include "common/log/log.h"

class Db;

/**
 * @brief 表示创建表的语句
 * @ingroup Statement
 * @details 虽然解析成了stmt，但是与原始的SQL解析后的数据也差不多
 */
class DropTableStmt : public Stmt
{
public:
  DropTableStmt(const std::string &table_name) : table_name_(table_name) {}
  virtual ~DropTableStmt() = default;

  StmtType type() const override { return StmtType::DROP_TABLE; }

  const std::string &table_name() const { return table_name_; }

  static RC create(Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt);  //创建drop table语法树节点

private:
  std::string table_name_;  //存储删除的表名
};