#include "../Public/UpdateLangPackTooLong.h"


//begin namespace block
namespace COMMON
{

UpdateLangPackTooLong::UpdateLangPackTooLong()
{
	this->_ConstructorID = 281165899;
}
void UpdateLangPackTooLong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateLangPackTooLong::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdateLangPackTooLong::~UpdateLangPackTooLong()
{

}
}//end namespace block
