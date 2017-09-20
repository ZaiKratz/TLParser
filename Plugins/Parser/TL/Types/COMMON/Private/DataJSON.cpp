#include "../Public/DataJSON.h"


//begin namespace block
namespace COMMON
{

DataJSON::DataJSON()
{
	this->_ConstructorID = 76379261;
}

DataJSON::DataJSON(FString data)
{
	this->_ConstructorID = 76379261;
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
}
DataJSON::~DataJSON()
{

}
}//end namespace block
