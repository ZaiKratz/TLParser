#include "../Public/UpdateMessageID.h"


//begin namespace block
namespace COMMON
{

UpdateMessageID::UpdateMessageID()
{
	this->_ConstructorID = 1318109142;
}

UpdateMessageID::UpdateMessageID(int32 id, unsigned long long random_id)
{
	this->_ConstructorID = 1318109142;
	this->id = id;
	this->random_id = random_id;
}
void UpdateMessageID::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteLong(this->random_id);
}


void UpdateMessageID::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	random_id = Reader.ReadLong();
	this->_Responded = true;
}
UpdateMessageID::~UpdateMessageID()
{

}
}//end namespace block
