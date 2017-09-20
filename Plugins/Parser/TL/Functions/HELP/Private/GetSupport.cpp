#include "../Public/GetSupport.h"


//begin namespace block
namespace HELP
{

GetSupport::GetSupport()
{
	this->_ConstructorID = -855056484;
	this->_ContentRelated = true;
}
void GetSupport::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetSupport::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::Support*>(Reader.TGReadObject());
}
GetSupport::~GetSupport()
{

}
}//end namespace block
