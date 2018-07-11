    $(function (){
        $('form').bootstrapValidator({
            feedbackIcons:{
                            valid:'glyphicon glyphicon-ok',
                            invalid:'glyphicon glyphicon-remove',
                            validating:'glyphicon glyphicon-refresh'
                            },
            fields:{
                username:{
                    validators:{
                        notEmpty:{
                            message:'用户名不能为空'
                        },
                        stringLength:{
                            min:1,
                            max:10,
                            message:'用户名长度必须在1到10位之间'
                        },
                        regexp:{
                            regexp:/^[a-zA-Z0-9_]+$/,
                            message:'用户名只能包含大写、小写、数字和下划线'
                        }
                    }
                },
                email:{
                    validators:{
                        notEmpty:{
                            message:'邮箱地址不能为空'
                        },
                        emailAddress:{
                            message:'邮箱地址格式有误'
                        }
                    }
                },
                password:{
                    validators:{
                        notEmpty:{
                            message:'密码不能为空'
                        },
                        stringLength:{
                            min:6,
                            max:15,
                            message:'密码长度必须在6到15位之间'
                        },
                        regexp:{
                            regexp:/^[a-zA-Z0-9_]+$/,
                            message:'密码只能包含大写、小写、数字和下划线'
                        }
                    }
                },
            }
        });
    });




/* $(function () {
        $('form').bootstrapValidator({
　　　　　　　message: 'This value is not valid',
            　feedbackIcons: {
                　　　　　　　　valid: 'glyphicon glyphicon-ok',
                　　　　　　　　invalid: 'glyphicon glyphicon-remove',
                　　　　　　　　validating: 'glyphicon glyphicon-refresh'
            　　　　　　　　  },
              fields: {
                username: {
                    validators: {
                        notEmpty: {
                            message: '用户名不能为空'
                        },
						 stringLength: {
                            min: 3,
                            max: 18,
                            message: '用户名长度必须在3到18位之间'
                        },
                        regexp: {
                            regexp: /^[a-zA-Z0-9_]+$/,
                            message: '用户名只能包含大写、小写、数字和下划线'
                        }
                    }
                },
				password:{
                    validators: {
                        notEmpty: {
                            message: '密码不能为空'
                        },
                    }
				},
				rpassword:{
                    validators: {
                        notEmpty: {
                            message: '密码不能为空'
                        },
						identical: {
							field: 'password',
							message: '两次输入的密码不一致'
						}
            
                    }
				},
                email: {
                    validators: {
                        notEmpty: {
                            message: '邮箱地址不能为空'
                        },
						emailAddress: {
                            message: '邮箱地址格式有误'
                        }
                    }
                }
            }
        });
    });
*/