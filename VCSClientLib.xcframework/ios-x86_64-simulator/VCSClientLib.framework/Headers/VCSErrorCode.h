
/// Error错误码
typedef enum{
    /// "网络错误"
    VCS_ERR_NET_ERROR                         = 10001,
    /// "引擎未初始化"
    VCS_ERR_ENGINE_NOT_INITIALIZE             = 10002,
    /// "内部信令发送失败"
    VCS_ERR_INNER_MESSAGE_SEND_FAILED         = 10003,
    // （10004～10007废弃⚠️）
//    /// "内部错误",通常因为引擎处于初始化中或销毁中导致当前操作执行失败
//    VCS_ERR_INNER_ERROR                       = 10004,
//    /// "内部 RTC 错误"
//    VCS_ERR_RTC_ERROR                         = 10005,
//    /// "Token 已过期"
//    VCS_ERR_TOKEN_EXPIRED                     = 10006,
//    /// "Token 无效"
//    VCS_ERR_TOKEN_INVALID                     = 10007,
    /// "接收方为空"
    VCS_ERR_MESSAGESEND_TO_NULL               = 10008,
    /// "接口返回错误"
    VCS_ERR_INTERFACE_ERROR                   = 10009,
    /// "参数校验错误"
    VCS_ERR_GENERAL                           = 10010,
    /// "服务器超时"
    VCS_ERR_SERVER_TIMEOUT                    = 10011,
    /// "未知服务器错误"
    VCS_ERR_SERVER_UNKONWN                    = 10012,
    /// "重复发起呼叫错误"
    VCS_ERR_REPEATCALL                        = 10013,
    /// "重复登录错误"
    VCS_ERR_REPEAT_LOGIN                      = 10014,
    /// "RTM登录失败"
    VCS_ERR_RTM_LOGIN_FAILED                  = 10015,
    /// "RTM订阅失败"
    VCS_ERR_RTM_SUBSCRIBE_FAILED              = 10016,
    /// "RTM取消订阅失败"
    VCS_ERR_RTM_CANCELSUBSCRIBE_FAILED        = 10017,
    /// "RTM登出失败"
    VCS_ERR_RTM_LOGOUT_FAILED                 = 10018,
    
}VCSErrorCode;
