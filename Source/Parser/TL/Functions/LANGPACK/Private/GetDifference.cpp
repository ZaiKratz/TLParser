#include "../Public/GetDifference.h"


//begin namespace block
namespace LANGPACK
{

GetDifference::GetDifference()
{
	this->_ConstructorID = 187583869;
	this->_ContentRelated = true;
}

GetDifference::GetDifference(int32 from_version)
{
	this->_ConstructorID = 187583869;
	this->_ContentRelated = true;
	this->from_version = from_version;
}
void GetDifference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->from_version);
}


void GetDifference::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::LangPackDifference*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetDifference::~GetDifference()
{

}
}//end namespace block
