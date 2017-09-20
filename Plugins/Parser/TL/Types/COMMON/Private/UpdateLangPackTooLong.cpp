#include "../Public/UpdateLangPackTooLong.h"


//begin namespace block
namespace COMMON
{

UpdateLangPackTooLong::UpdateLangPackTooLong()
{
	this->_ConstructorID = 1262535184;
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
}
UpdateLangPackTooLong::~UpdateLangPackTooLong()
{

}
}//end namespace block
