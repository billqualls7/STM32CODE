#include "bsp_clkconfig.h"

void USer_SetSysClock(void)
{
	
	
	
	
	
/******************************************************************************/
/*            PLL (clocked by HSE) used as System clock source                */
/******************************************************************************/
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  RCC_DeInit();
  /* Enable HSE */
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* Wait till HSE is ready and if Time out is reached exit */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }

	
//	HSE �����ɹ�
  if (HSEStatus == (uint32_t)0x01)
  {
    /* Select regulator voltage output Scale 1 mode */
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    /* HCLK = SYSCLK / 1*/
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;


    /* PCLK2 = HCLK / 2*/
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
    
    /* PCLK1 = HCLK / 4*/
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
		
    /* Configure the main PLL */
//    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
//                   (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);
		
    RCC->PLLCFGR = 25 | (192 << 6) | (((2 >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (7 << 24);		
  
    /* Enable the main PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* Wait till the main PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }   
 
    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
    //����FLASH��Ԥȡֵ��ָ��棬�ȴ�����
		FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

    /* Select the main PLL as system clock source */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* Wait till the main PLL is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
    {
    }
  }
  else
  { /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
  }


}






void HSE_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q)
{
	ErrorStatus HSE_ErrorStatus=ERROR;
	//��λ���мĴ���
  RCC_DeInit();
  /* Enable HSE */
 
	RCC_HSEConfig(RCC_HSE_ON);
	/* �ȴ������ȶ� */
	HSE_ErrorStatus=RCC_WaitForHSEStartUp();
	if (HSE_ErrorStatus == SUCCESS)
	{
		// ��ѹ����ѹ�����������Ϊ1���Ա�������Ϊ���Ƶ��
		// ����ʱʹ���ܺ͹���ʵ��ƽ��
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div4);
    RCC_PCLK2Config(RCC_HCLK_Div2);
		
		RCC_PLLConfig(RCC_PLLSource_HSE, m, n, p, q);
		RCC_PLLCmd(ENABLE);
	  
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{}
		
	  // ����FLASHԤȡָ,ָ���,���ݻ���͵ȴ�״̬
    FLASH->ACR = FLASH_ACR_PRFTEN 
		            | FLASH_ACR_ICEN 
		            |FLASH_ACR_DCEN 
		            |FLASH_ACR_LATENCY_5WS;
			
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource()!=0x08)
		{
		
		}
	
	
	}
	else
	{
		// ����ʧ��
	
	
	}
 
 

}







void HSI_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q)
{
	__IO uint32_t HSIStartUpStatus = 0;
	//��λ���мĴ���
  RCC_DeInit();
  /* Enable HSE */
 
	RCC_HSICmd(ENABLE);
	/* �ȴ������ȶ� */
	HSIStartUpStatus = RCC->CR & RCC_CR_HSIRDY;
	if (HSIStartUpStatus == RCC_CR_HSIRDY)
	{
		// ��ѹ����ѹ�����������Ϊ1���Ա�������Ϊ���Ƶ��
		// ����ʱʹ���ܺ͹���ʵ��ƽ��
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div4);
    RCC_PCLK2Config(RCC_HCLK_Div2);
		
		RCC_PLLConfig(RCC_PLLSource_HSI, m, n, p, q);
		RCC_PLLCmd(ENABLE);
	  
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{}
		
	  // ����FLASHԤȡָ,ָ���,���ݻ���͵ȴ�״̬
    FLASH->ACR = FLASH_ACR_PRFTEN 
		            | FLASH_ACR_ICEN 
		            |FLASH_ACR_DCEN 
		            |FLASH_ACR_LATENCY_5WS;
			
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource()!=0x08)
		{
		
		}
	
	
	}
	else
	{
		// ����ʧ��
	
	
	}
 
 

}







void MCO1_GPIO_Congig(void)
{
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOA, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	


		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;   
    
    /*�������ŵ��������Ϊ�������*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    /*��������Ϊ����ģʽ*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;


		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

		/*���ÿ⺯����ʹ���������õ�GPIO_InitStructure��ʼ��GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);		


}






void MCO2_GPIO_Congig(void)
{
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOC, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	


		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;   
    
    /*�������ŵ��������Ϊ�������*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    /*��������Ϊ����ģʽ*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;


		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

		/*���ÿ⺯����ʹ���������õ�GPIO_InitStructure��ʼ��GPIO*/
		GPIO_Init(GPIOC, &GPIO_InitStructure);		


}











