#include "../Public/MessageRange.h"


//begin namespace block
namespace COMMON
{

MessageRange::MessageRange()
{
	this->_ConstructorID = 64;
}

MessageRange::MessageRange(int32 min_id, int32 max_id)
{
	this->_ConstructorID = 64;
	this->min_id = min_id;
	this->max_id = max_id;
}
void MessageRange::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->min_id);
	Writer.WriteInt(this->max_id);
}


void MessageRange::OnResponce(BinaryReader& Reader)
{
	min_id = Reader.ReadInt();
	max_id = Reader.ReadInt();
}
MessageRange::~MessageRange()
{

}
}//end namespace block
