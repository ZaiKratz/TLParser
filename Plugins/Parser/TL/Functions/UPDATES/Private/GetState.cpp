#include "../Public/GetState.h"


//begin namespace block
namespace UPDATES
{

GetState::GetState()
{
	this->_ConstructorID = 713610477;
	this->_ContentRelated = true;
}
void GetState::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetState::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPDATES::State*>(Reader.TGReadObject());
}
GetState::~GetState()
{

}
}//end namespace block
