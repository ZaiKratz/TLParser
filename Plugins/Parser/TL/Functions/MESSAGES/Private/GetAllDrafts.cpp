#include "../Public/GetAllDrafts.h"


//begin namespace block
namespace MESSAGES
{

GetAllDrafts::GetAllDrafts()
{
	this->_ConstructorID = 1703755626;
	this->_ContentRelated = true;
}
void GetAllDrafts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAllDrafts::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
GetAllDrafts::~GetAllDrafts()
{

}
}//end namespace block
