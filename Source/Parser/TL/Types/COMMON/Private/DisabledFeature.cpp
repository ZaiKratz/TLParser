#include "../Public/DisabledFeature.h"


//begin namespace block
namespace COMMON
{

DisabledFeature::DisabledFeature()
{
	this->_ConstructorID = -1369215196;
}

DisabledFeature::DisabledFeature(FString feature, FString description)
{
	this->_ConstructorID = -1369215196;
	this->feature = feature;
	this->description = description;
}
void DisabledFeature::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->feature);
	Writer.TGWriteString(this->description);
}


void DisabledFeature::OnResponce(BinaryReader& Reader)
{
	feature = Reader.TGReadString();
	description = Reader.TGReadString();
	this->_Responded = true;
}
DisabledFeature::~DisabledFeature()
{

}
}//end namespace block
