#include "../Public/UpdateContactRegistered.h"


//begin namespace block
namespace COMMON
{

UpdateContactRegistered::UpdateContactRegistered()
{
	this->_ConstructorID = 628472761;
}

UpdateContactRegistered::UpdateContactRegistered(int32 user_id, FDateTime date)
{
	this->_ConstructorID = 628472761;
	this->user_id = user_id;
	this->date = date;
}
void UpdateContactRegistered::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteDate(this->date);
}


void UpdateContactRegistered::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	this->_Responded = true;
}
UpdateContactRegistered::~UpdateContactRegistered()
{

}
}//end namespace block
