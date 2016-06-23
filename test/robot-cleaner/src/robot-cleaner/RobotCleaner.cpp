#include <robot-cleaner/RobotCleaner.h>
#include <robot-cleaner/Instructions.h>

RobotCleaner::RobotCleaner()
  : position(0, 0, NORTH)
{}

void RobotCleaner::exec(Instruction* instruction)
{
    instruction->exec(CUI_SELF(position, Point), CUI_SELF(position, Position));
    delete instruction;
}

const Position& RobotCleaner::getPosition() const
{
    return position;
}
