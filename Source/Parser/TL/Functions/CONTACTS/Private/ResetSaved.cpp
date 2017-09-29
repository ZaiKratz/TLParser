#include "../Public/ResetSaved.h"


//begin namespace block
namespace CONTACTS
{

ResetSaved::ResetSaved()
{
	this->_ConstructorID = -2020263951;
	this->_ContentRelated = true;
}
void ResetSaved::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ResetSaved::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ResetSaved::~ResetSaved()
{

}
}//end namespace block
