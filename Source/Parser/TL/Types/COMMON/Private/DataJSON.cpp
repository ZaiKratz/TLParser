#include "../Public/DataJSON.h"


//begin namespace block
namespace COMMON
{

DataJSON::DataJSON()
{
	this->_ConstructorID = 2104790276;
}

DataJSON::DataJSON(FString data)
{
	this->_ConstructorID = 2104790276;
	this->data = data;
}
void DataJSON::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->data);
}


void DataJSON::OnResponce(BinaryReader& Reader)
{
	data = Reader.TGReadString();
	this->_Responded = true;
}
DataJSON::~DataJSON()
{
}
}//end namespace block
