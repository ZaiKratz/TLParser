#include "../Public/ResetSaved.h"


//begin namespace block
namespace CONTACTS
{

ResetSaved::ResetSaved()
{
	this->_ConstructorID = -248015481;
	this->_ContentRelated = true;
}
void ResetSaved::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ResetSaved::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ResetSaved::~ResetSaved()
{

}
}//end namespace block
